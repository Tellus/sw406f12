/*
 * AbilityTable.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "AbilityTable.h"

namespace engine {

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

GameState *AbilityTable::get_next_state()
{
/**
 Steps:
   1. Get active Char (this->source).
   2. Get full Ability[x]Target table with validated abilities and targets.
   3. For each valid Action:
    a. Clone a new GameState, execute the Action and return the piggy value.
    b. Highest piggy value (and GameState) is stored. The others are discarded.
   4. Return resulting max state.
**/

    // 1 + 2
    std::cout << "Creating viable actions...";
    std::vector<Action*> *actions = this->create_actions(this->state->current_char);
    std::cout << " DONE!\nCalculating best piggy action...";

    // 3
    float max_piggy = 0;
    for (std::vector<Action*>::iterator iter = actions->begin();
         iter != actions->end();
         iter++)
    {
        float new_pig = this->get_action_piggy(*iter);
        if (new_pig > max_piggy)
        {
            max_piggy = new_pig;
            this->best_action = *iter;
        }
    }
    
    std::cout << " DONE!\nReturning cloned state.\n";
    
    delete actions;
    
    // 4.
    return new GameState(*this->state);
}

float AbilityTable::get_action_piggy(Action *a)
{
    GameState *clone = new GameState(*this->state);
    
    // Set correct (relative) pointers.
    a->source = clone->current_char;
    a->target = clone->get_rgr(*a->target_rgr);
    
    // Run.
    a->execute();
    
    // Get piggy.
    Character *ch = (Character*)a->source;
    float piggy = ch->get_piggy();
    
    // Destroy clone.
    delete clone;
    
    // Return piggy.
    return piggy;
}

std::vector<Action*> *AbilityTable::create_actions(Character *from)
{
//    std::cout << "create_actions:\n";
    // Get a short-hand.
    std::map<std::string, Ability*> abils = from->get_abilities();
    
    // Initialize action list
    this->actions = new std::vector<Action*>();
    
    // Final list of usable abilities.
    std::list<Ability*> usable;
    
    //
    std::map<std::string, Ability*>::iterator iter;
    Ability *abil;
    
//    std::cout << "Filtering out unusable abilities... ";
    // Discard all unusable Ability objects.
    for (iter = abils.begin();
         iter != abils.end();
         iter++)
    {
        // Get abil. Test cost.
        abil = (iter->second);
        if (abil->cost_health <= from->get_resource("Health")->get_current() &&
            abil->cost_mana <= from->get_resource("Mana")->get_current())
                usable.push_back((iter->second));
    }
//    std::cout << "DONE!\nFinding Ability/Target combinations for Actions...";
    
    // Create the Action list.
    
    // Loop through each ability.
    for (std::list<Ability*>::iterator abil_iter = usable.begin();
         abil_iter != usable.end();
         abil_iter++)
    {
        // Loop through the list of available targets.
        std::list<RGR_Enum> targets = (*abil_iter)->get_as_list();
        for (std::list<RGR_Enum>::iterator tar_iter = targets.begin();
             tar_iter != targets.begin();
             tar_iter++)
        {
            // Assert the target and, if valid, create the action.
            if (this->state->get_rgr(*tar_iter) == NULL)
            {
                std::cout << "Failed to retrieve RGR for " << RGR_List::to_string(*tar_iter) << ".\n";
            }
            else
            {
                // Add it to the list of validated actions. Notice how we use
                // the RGR_Enum variant of the initializer. At this point, we
                // don't have a GameState clone to affect, yet, and thus still
                // need the relative reference.
                this->actions->push_back(new Action(from, *abil_iter, *tar_iter));
            }
        }
    }
    
//    std::cout << "DONE!\nReturning...\n";
    
    return this->actions;
}

void AbilityTable::iterate_ability(Ability *src)
{
    // get valid targets.
	auto tars = src->get_as_list();
}

Action *AbilityTable::get_next_action()
{
    if (this->best_action == NULL)
    {
        get_next_state();
    }
    
    return this->best_action;
}

} /* namespace engine */
