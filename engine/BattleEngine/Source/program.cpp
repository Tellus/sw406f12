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
#include "EnemyIdentifier_Unsafe.h"
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

Character* make_joe()
{
    Character *johannes = new Character();
    johannes->name = "Johannes";
    
    // PrettyPrinter::print("Resources...\n", FG_YELLOW);
    johannes->add_resource("Health", new Resource(0, 100));
    johannes->add_resource("Mana", new Resource(0, 100));
    
    // PrettyPrinter::print("Attributes...\n", FG_YELLOW);
    johannes->add_attribute("Strength", new Attribute(17));
    johannes->add_attribute("Intelligence", new Attribute(25));
    johannes->add_attribute("Sexyness", new Attribute(10000));

	// Behaviour
    // add behaviour

    // Abilities.
    // PrettyPrinter::print("Abilities...\n", FG_YELLOW);
    johannes->add_ability("Sexy", new SexyAbility());
    johannes->add_ability("Heal", new HealAbility());
    johannes->add_ability("Attack", new AttackAbility());

	return johannes;
}

Character* make_biggi()
{
    Character *biggi = new Character();
    biggi->name = "Biggi";
    
    // PrettyPrinter::print("Resources...\n", FG_YELLOW);
    biggi->add_resource("Health", new Resource(0, 250));
    biggi->add_resource("Mana", new Resource(0, 50));
    
    // PrettyPrinter::print("Attributes...\n", FG_YELLOW);
    biggi->add_attribute("Strength", new Attribute(50));
    biggi->add_attribute("Intelligence", new Attribute(10));
    biggi->add_attribute("Sexyness", new Attribute(5));
    // Behaviour
    // add behaviour

    // Abilities.
    // PrettyPrinter::print("Abilities...\n", FG_YELLOW);
    biggi->add_ability("Maul", new AttackAbility());

	return biggi;
}

GameState* make_base_state()
{
	GameState::register_identifier(new EnemyIdentifier());
    GameState::register_identifier(new OwnerIdentifier());

    GameState *state = new GameState();

	Character* joe = make_joe();
	Character* big = make_biggi();

	state->add_character(joe);
	if (!state->set_team_aff(1, joe))
	{
		PrettyPrinter::print_bad("Joe could not be put on a team!\n");
	}
	state->add_character(big);
	if (!state->set_team_aff(2, big))
	{
		PrettyPrinter::print_bad("Biggi could not be put on a team!\n");
	}
	state->current_char = state->characters.front();

	return state;
}

void test_gamestate_clone(GameState* from)
{
	PrettyPrinter::print("Testing GameState clone function.\n");
    
    GameState *tmp_state = from->clone();
    
    tmp_state->pretty_print();

	delete tmp_state;
}

int main(int argc, char *argv[])
{
    PrettyPrinter::print("BattleEngine v1 alpha.\n", FG_YELLOW);

    PrettyPrinter::print("Initialize new character...\n");

    // Let's do a simple verification test: Create and populate a character.
	Character* johannes = make_joe();
    johannes->pretty_print();

	Character* biggi = make_biggi();
	biggi->pretty_print();

	// Erase tracks again. Good for mem... mom?
	delete biggi;
	delete johannes;

    PrettyPrinter::print_good("Character init test: DONE!\n");
    
    PrettyPrinter::print("Creating intermediate GameState.\n");

	GameState* state = make_base_state();
    
    state->pretty_print();
    
	// Uncomment to test deep cloning support.
	// test_gamestate_clone(state);
    
    PrettyPrinter::print("Running AbilityTable on GameState.\n");
    
    AbilityTable *at = new AbilityTable(state);
    
    // PrettyPrinter::print("Calculating best future state...\n");
	cout << "Calculating best future state from " << state << "...\n";
    
    state = at->get_next_state();
    
    PrettyPrinter::print_good("Future state: DONE!\n");
    
    state->pretty_print();
    
    PrettyPrinter::print_good("We're done! Thank you.");
    
	PrettyPrinter::print("Press any key to exit.");
	string str;
	cin >> str;

	return 0;
}
