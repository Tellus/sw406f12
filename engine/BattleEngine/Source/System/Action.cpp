/*
 * Action.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Action.h"

namespace engine {

Action::Action(RGR_Enum source, RGR_Enum target, Ability* abil)
{
    this->action_def = ActionDefinition(source, target, abil);
    // HI!
}

Action::Action(ActionDefinition to_use)
{
    this->action_def = to_use;
    // Oh, hai!
}


Action::~Action() {
	// TODO Auto-generated destructor stub
}

GameState* Action::execute(GameState *thru)
{
	// Clone.
	GameState* state = thru->clone();

	Character* source = state->get_rgr(this->action_def.source);
	Character* target = state->get_rgr(this->action_def.target);

	// Set target.
	state->set_target(target);

	std::vector<Effect*> *effects = this->generate_effects();
	
//    std::cout << "Applying " << effects->size() << " to targets.\n";
	
	for (std::vector<Effect*>::iterator iter = effects->begin(); iter != effects->end(); iter++)
	{
		Effect* ef = *iter;

        std::cout << '\t' << ef->name << '\n';

		ef->execute(source, target);
	}

//    std::cout << "Action execution done.\n";

    // Remove the costs from resources.
    source->get_resource("health")->decrease(this->action_def.ability->cost_health);
    source->get_resource("mana")->decrease(this->action_def.ability->cost_mana);

	return state;
}

std::vector<Effect*> *Action::generate_effects()
{
	std::vector<Effect*> *tmp = &this->action_def.ability->effects;
	std::vector<Effect*> *out = new std::vector<Effect*>();;

	Effect *ef;

	for(std::vector<Effect*>::iterator i = tmp->begin(); i != tmp->end(); i++)
	{
		ef = (*i);
		out->push_back(dynamic_cast<Effect*>(ef->clone()));
	}
	return out;
}

Action* Action::clone()
{
    return new Action(
                            this->action_def.source,this->action_def.target,
                            dynamic_cast<Ability*>(this->action_def.ability->clone()));
}

} /* namespace engine */
