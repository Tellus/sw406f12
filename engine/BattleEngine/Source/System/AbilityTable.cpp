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

	this->best_action = NULL;

    // 1 + 2
    frontend::PrettyPrinter::print("Creating viable actions...\n");
    std::vector<Action*> *actions = this->create_actions(this->state->current_char);
    frontend::PrettyPrinter::print("Final actions found! ", frontend::FG_GREEN);
    std::cout << "(" << actions->size() << ")\n";

    // 3
    if (actions->size() == 0)
    {
        frontend::PrettyPrinter::print_bad("\nERROR!");
        frontend::PrettyPrinter::print(" There are no viable actions!\n");
        
        return NULL;
    }
    
	frontend::PrettyPrinter::print("Calculating best piggy action...\n");

	// Highest piggy rating so far... minimal value.
	float max_piggy = std::numeric_limits<float>::infinity() * -1;

    for (std::vector<Action*>::iterator iter = actions->begin();
         iter != actions->end();
         iter++)
    {
        Action *tmp_a = *iter;

		GameState *tmp_state = tmp_a->execute(this->state);

		float new_piggy = tmp_state->current_char->get_piggy(tmp_state);

		if (new_piggy > max_piggy)
		{
			std::cout << "Better action supplanting previous.\n";
			max_piggy = new_piggy;
			this->best_action = *iter;
			this->best_state = tmp_state;
		}
		else
		{
			std::cout << "Current piggy is best.\n";
			delete tmp_state;
		}
    }
    
    frontend::PrettyPrinter::print_good("DONE!\n");
        
    if (this->best_action == NULL)
    {
        std::cout << "ERROR! Null Action!\n";
    }
    else if (this->best_action->ability == 0 || this->best_action->ability == NULL)
    {
        std::cout << "ERROR! Ability was null for some reason!\n";
    }
    else
    {
        std::cout << "Best action:\n";
        this->best_action->ability->pretty_print();
    }
    
    std::cout << "Returning cloned state.\n";

    delete actions;
    
    // 4.
    // return new GameState(*this->state);
	return this->best_state;
}

float AbilityTable::get_action_piggy(Action *a)
{
	GameState *new_state = a->execute(this->state);
    
    // Get piggy.
	Character *ch = new_state->get_rgr(a->source);
    float piggy = ch->get_piggy(new_state);
    
    // Destroy clone.
    delete new_state;
    
    // Return piggy.
    return piggy;
}

std::vector<Action*> *AbilityTable::create_actions(Character *from)
{
    // Get a short-hand.
    std::map<std::string, Ability*> abils = from->get_abilities();
    
    // Initialize action list
    this->actions = new std::vector<Action*>();
    
    // Final list of usable abilities.
    std::list<Ability*> usable;
    
    std::map<std::string, Ability*>::iterator iter;
    Ability *abil;
 
    frontend::PrettyPrinter::print("Filtering out non-usable actions (of ");
    std::cout << abils.size();
    frontend::PrettyPrinter::print(").\n");

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
    
    frontend::PrettyPrinter::print("Final count: ");
    std::cout << usable.size() << '\n';
    
    // Create the Action list.
    
    frontend::PrettyPrinter::print("Getting all viable Ability/Target combos...\n");
    
    // Loop through each ability.
    for (std::list<Ability*>::iterator abil_iter = usable.begin();
         abil_iter != usable.end();
         abil_iter++)
    {
		std::list<RGR_Enum> targets = (*abil_iter)->get_as_list();

		frontend::PrettyPrinter::print("| Considering " + (*abil_iter)->name + '\n');
        
        // Loop through the list of available targets.
        
        for (std::list<RGR_Enum>::iterator tar_iter = targets.begin();
             tar_iter != targets.end();
             tar_iter++)
        {
            // Assert the target and, if valid, create the action.
			frontend::PrettyPrinter::print("\t" + RGR_List::to_string(*tar_iter) + "... ");

			Character *targ;
			try
			{
				targ = this->state->get_rgr(*tar_iter);
				// Add it to the list of validated actions. Notice how we use
				// the RGR_Enum variant of the initializer. At this point, we
				// don't have a GameState clone to affect, yet, and thus still
				// need the relative reference.
				// TODO: Make something more elegant than always sourcing the character OWNER.
				this->actions->push_back(new Action(OWNER, (*tar_iter), *abil_iter));
				frontend::PrettyPrinter::print_good(" OK\n");
			}
			catch (engine::InvalidRGRException e)
			{
				// throw e;
				frontend::PrettyPrinter::print_bad(" FAIL (" + e.msg + ")\n");
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
