/*
 * AbilityTable.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "AbilityTable.h"

namespace engine {

AbilityTable::AbilityTable()
{
	this->_init();
}

AbilityTable::AbilityTable(GameState *f)
{
    this->_init();
    
    this->state = f;
}

AbilityTable::~AbilityTable()
{
	// TODO Auto-generated destructor stub
}

void AbilityTable::_init()
{
    // Do nothing!!!
    return;
}

GameState* AbilityTable::force_action(ActionDefinition* action)
{
    Action* tmp_a = new Action(*action);

    return tmp_a->execute(this->state);
}

GameState *AbilityTable::get_next_state()
{
/**
 Steps:
   0. If queued action, run immediately and return.
   1. Get active Char (this->source).
   2. Get full Ability[x]Target table with validated abilities and targets.
   3. For each valid Action:
    a. Clone a new GameState, execute the Action and return the piggy value.
    b. Highest piggy value (and GameState) is stored. The others are discarded.
   4. Return resulting max state.
**/
    Character* ctmp = this->state->current_char;
    
    std::list<EventListener*>* events = ctmp->get_events();
    std::list<EventListener*>::iterator el_iter;
    
    EventCondition* cond;
    Character* e_targ;
    
    for (el_iter = events->begin();
         el_iter != events->end();
         el_iter++)
    {
        cond = (*el_iter)->condition;
        e_targ = this->state->get_rgr(cond->target);
        
        if (cond->compare(e_targ->get_child(cond->member)->get_value()))
        {
            // Force.
            return force_action((*el_iter)->action);
        }
    }

	this->best_action = NULL;

    // 1 + 2
    std::vector<Action*> *actions = this->create_actions(this->state->current_char);

    // 3
    if (actions->size() == 0)
		throw NoValidActionException("No viable actions possible!");

	// Highest piggy rating so far... minimal value.
	float max_piggy = std::numeric_limits<float>::infinity() * -1;

    for (std::vector<Action*>::iterator iter = actions->begin();
         iter != actions->end();
         iter++)
    {
        Action *tmp_a = *iter;

		GameState *tmp_state = tmp_a->execute(this->state);

		float new_piggy = tmp_state->current_char->get_piggy(tmp_state);

        std::cout << this->state->current_char->name
                  << ": using "
                  << tmp_a->action_def.ability->name
                  << " results in a piggy value of "
                  << new_piggy
                  << '\n';

		if (new_piggy > max_piggy)
		{
			// Better action found.
			max_piggy = new_piggy;
			this->best_action = *iter;
			this->best_state = tmp_state;
		}
		else
		{
			// Not a better action found.
			// delete tmp_state;
		}
    }
        
    if (this->best_action == NULL)
        std::cout << "ERROR! Null Action!\n";
    else if (this->best_action->action_def.ability == NULL)
        std::cout << "ERROR! Ability was null for some reason!\n";

    delete actions;
    
    // 4.
	return this->best_state;
}

float AbilityTable::get_action_piggy(Action *a)
{
	GameState *new_state = a->execute(this->state);
    
    // Get piggy.
	Character *ch = new_state->get_rgr(a->action_def.source);
    float piggy = ch->get_piggy(new_state);
    
    // Destroy clone.
    delete new_state;
    
    // Return piggy.
    return piggy;
}

std::vector<Action*> *AbilityTable::create_actions(Character *from)
{
    // Get a short-hand.
    std::map<std::string, Ability*> abils = *from->get_abilities();
    
    // Initialize action list
    this->actions = new std::vector<Action*>();
    
    // Final list of usable abilities.
    std::list<Ability*> usable;
    
    std::map<std::string, Ability*>::iterator iter;
    Ability *abil;

    // Discard all unusable Ability objects.
    for (iter = abils.begin();
         iter != abils.end();
         iter++)
    {
        // Get abil. Test cost.
        abil = (iter->second);
        std::cout << abil->name
                  << " costs ("
                  << abil->cost_health
                  << '/'
                  << abil->cost_mana
                  << ") - ";
        if (abil->cost_health <= from->get_resource("health")->get_current() &&
            abil->cost_mana <= from->get_resource("mana")->get_current())
        {
            std::cout << "OK\n";
            usable.push_back((iter->second));
        }
        else
        {
            std::cout << "FAIL\n";
        }
    }
    
    // Loop through each ability.
    for (std::list<Ability*>::iterator abil_iter = usable.begin();
         abil_iter != usable.end();
         abil_iter++)
    {
		std::list<RGR_Enum> targets = (*abil_iter)->get_as_list();

        // Loop through the list of available targets.
        
        for (std::list<RGR_Enum>::iterator tar_iter = targets.begin();
             tar_iter != targets.end();
             tar_iter++)
        {
            // Assert the target and, if valid, create the action.
			Character* targ;
			try
			{
				targ = this->state->get_rgr(*tar_iter);

				// Add it to the list of validated actions. Notice how we use
				// the RGR_Enum variant of the initializer. At this point, we
				// don't have a GameState clone to affect, yet, and thus still
				// need the relative reference.
				// TODO: Make something more elegant than always sourcing the character OWNER.
				this->actions->push_back(new Action(OWNER, (*tar_iter), *abil_iter));
			}
			catch (engine::InvalidRGRException e)
			{
				// Bad RGR.
				// TODO: Uncomment the next line to get an exception every time a bad RGR is requested.
				// throw e;
			}
        }
    }

    return this->actions;
}

void AbilityTable::iterate_ability(Ability *src)
{
    // get valid targets.
	auto tars = src->get_as_list();
}

} /* namespace engine */
