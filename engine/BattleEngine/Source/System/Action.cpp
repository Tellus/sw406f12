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
    this->source = source;
    this->target = target;
    this->ability = abil;
}

Action::~Action() {
	// TODO Auto-generated destructor stub
}

GameState* Action::execute(GameState *thru)
{
	// Clone.
	GameState* state = thru->clone();

	Character* source = state->get_rgr(this->source);
	Character* target = state->get_rgr(this->target);

	std::vector<Effect*> *effects = this->generate_effects();
	for (std::vector<Effect*>::iterator iter = effects->begin(); iter != effects->end(); iter++)
	{
		Effect *ef = dynamic_cast<Effect*>(*iter);

		ef->execute(source, target);
	}

	return state;
}

std::vector<Effect*> *Action::generate_effects()
{
	std::vector<Effect*> *tmp = &this->ability->effects;
	std::vector<Effect*> *out = new std::vector<Effect*>();;

	Effect *ef;

	for(std::vector<Effect*>::iterator i = tmp->begin(); i != tmp->end(); i++)
	{
		ef = (*i);
		out->push_back(dynamic_cast<Effect*>(ef->clone()));
	}
	return out;
}

} /* namespace engine */
