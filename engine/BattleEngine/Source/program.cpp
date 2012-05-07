/*
 * program.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

// For program.cpp
#include <iostream>

#include "Engine.h"
#include "SimpleWinCondition.h"

// For unit tests.
#include "GameState.h"
#include "AbilityTable.h"

#include "FullBehaviour.h"
#include "BehaviourRatios/ResourceRatio.h"
#include "BehaviourRatios/AttributeRatio.h"

#include "SexyAbility.h"
#include "HealAbility.h"
#include "AttackAbility.h"

// Other stuff.
#include "PrettyPrinter.h"

using namespace std;
using namespace engine;
using namespace frontend;
using namespace testbattle;

FullBehaviour* make_fighter_behaviour()
{
	FullBehaviour *nb = new FullBehaviour();
	nb->add_ratio(new ResourceRatio(ENEMY, "Health", -0.5));
	nb->add_ratio(new ResourceRatio(OWNER, "Health", 1));

	return nb;
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
	johannes->behaviour = make_fighter_behaviour();

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
	biggi->behaviour = make_fighter_behaviour();

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

	state->add_child(joe);
	if (!state->set_team_aff(1, joe))
	{
		PrettyPrinter::print_bad("Joe could not be put on a team!\n");
	}
	state->add_child(big);
	if (!state->set_team_aff(2, big))
	{
		PrettyPrinter::print_bad("Biggi could not be put on a team!\n");
	}
	state->current_char = dynamic_cast<Character*>(state->children.front());

	return state;
}

void test_gamestate_clone(GameState* from)
{
	PrettyPrinter::print("Testing GameState clone function.\n");
    
    GameState *tmp_state = from->clone();
    
    tmp_state->pretty_print();

	delete tmp_state;
}

void base_test()
{
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
}

int main(int argc, char *argv[])
{
    PrettyPrinter::print("BattleEngine v1 alpha.\n", FG_YELLOW);

	// Uncomment to perform basic initialization, cloning and AI test.
	// base_test();

	/*** BEGIN TRUE ENGINE TEST ***/

	Engine* game = new Engine();
	game->current_state->pretty_print();
	game->win_condition = new SimpleWinCondition();
	game->add_character(make_joe(),0);
	game->add_character(make_biggi(),1);
	game->run();

	game->current_state->pretty_print();

	/*** END TRUE ENGINE TEST ***/

	return 0;
}
