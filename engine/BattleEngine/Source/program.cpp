/*
 * program.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include <iostream>

#include "GameState.h"
#include "AbilityTable.h"

#include "SexyAbility.h"
#include "HealAbility.h"
#include "AttackAbility.h"

// Identifier includes. This should be made prettier.
#include "EnemyIdentifier.h"
#include "OwnerIdentifier.h"

// Other stuff.
#include "PrettyPrinter.h"

using namespace std;
using namespace engine;
using namespace frontend;
using namespace testbattle;

void sp(std::string to_print)
{
    cout << to_print << "\n";
}

int main(int argc, char *argv[])
{
    PrettyPrinter::print("BattleEngine v1 alpha.\n", FG_YELLOW);

    PrettyPrinter::print("Initialize new character...\n");

    // Let's do a simple verification test: Create and populate a character.
    Character *johannes = new Character();
    johannes->name = "Johannes";
    
    PrettyPrinter::print("Resources...\n", FG_YELLOW);
    johannes->add_resource("Health", new Resource(100, 0, 100));
    johannes->add_resource("Mana", new Resource(100, 0, 100));
    
    PrettyPrinter::print("Attributes...\n", FG_YELLOW);
    johannes->add_attribute("Strength", new Attribute(17));
    johannes->add_attribute("Intelligence", new Attribute(25));
    johannes->add_attribute("Sexyness", new Attribute(10000));
    // Behaviour
    // add behaviour
    // Abilities.
    
    PrettyPrinter::print("Abilities...\n", FG_YELLOW);
    johannes->add_ability("Sexy", new SexyAbility());
    johannes->add_ability("Heal", new HealAbility());
    johannes->add_ability("Attack", new AttackAbility());

    johannes->pretty_print();

    PrettyPrinter::print_good("DONE!\n");
    
    sp("Creating intermediate GameState.");
    
    GameState *state = new GameState();
    state->add_character(johannes);
    state->current_char = johannes;
    GameState::register_identifier(new EnemyIdentifier());
    GameState::register_identifier(new OwnerIdentifier());
    
    state->pretty_print();
    
    /**
    sp("Testing copy-constructor.");
    
    GameState *tmp_state = new GameState(*state);
    
    tmp_state->pretty_print();
    **/
    
    PrettyPrinter::print("Running AbilityTable on GameState.\n");
    
    AbilityTable *at = new AbilityTable(state);
    
    PrettyPrinter::print("Calculating best future state...\n");
    
    GameState *hit = at->get_next_state();
    
    PrettyPrinter::print_good("DONE!\n");
    
    hit->pretty_print();
    
    johannes->pretty_print();

    PrettyPrinter::print_good("Finalized. Thank you.");
    
	return 0;
}
