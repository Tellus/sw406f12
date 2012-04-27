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

#include "EnemyIdentifier.h"

using namespace std;
using namespace engine;
using namespace testbattle;

void sp(std::string to_print)
{
    cout << to_print << "\n";
}

int main(int argc, char *argv[])
{
    cout << "BattleEngine v1 alpha.\n";
    
    cout << "Testing console output.\n";
    
    cout << "\033[1;31mbold red text\033[0m\n";
    cout << "\[\033[32m]Hello, \[\033[36m]colourful \[\033[33mworld!\033[0m]\nm";

    cout << "Initializing character...\n";

    // Let's do a simple verification test: Create and populate a character.
    Character *johannes = new Character();
    johannes->name = "Johannes";
    sp("\tResources...");
    johannes->add_resource("Health", new Resource(100, 0, 100));
    johannes->add_resource("Mana", new Resource(100, 0, 100));
    sp("\tAttributes...");
    johannes->add_attribute("Strength", new Attribute(17));
    johannes->add_attribute("Intelligence", new Attribute(25));
    johannes->add_attribute("Sexyness", new Attribute(10000));
    // Behaviour
    // add behaviour
    // Abilities.
    sp("\tAbilities...");
    johannes->add_ability("Sexy", new SexyAbility());
    johannes->add_ability("Heal", new HealAbility());
    johannes->add_ability("Attack", new AttackAbility());

    johannes->pretty_print();

    sp("Done!");
    
    sp("Creating intermediate GameState.");
    
    GameState *state = new GameState();
    state->add_character(johannes);
    state->current_char = johannes;
    GameState::register_identifier(new EnemyIdentifier());
    
    state->pretty_print();
    
    /**
    sp("Testing copy-constructor.");
    
    GameState *tmp_state = new GameState(*state);
    
    tmp_state->pretty_print();
    **/
    
    sp("Running AbilityTable on GameState.");
    
    AbilityTable *at = new AbilityTable(state);
    
    sp("Retrieving best state.");
    
    GameState *hit = at->get_next_state();
    
    sp("Printing best state.");
    
    hit->pretty_print();
    
    sp("There!");
    
    johannes->pretty_print();

	return 0;
}
