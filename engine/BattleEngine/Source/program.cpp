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
#include "BehaviourRatio.h"

#include "Effect.h"

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
	nb->add_ratio(new BehaviourRatio(ENEMY, "Health", -0.5));
	nb->add_ratio(new BehaviourRatio(OWNER, "Health", 2));

	return nb;
}

Character* make_joe_clean()
{
	Character *johannes = new Character();
	johannes->name = "Johannes";

	johannes->add_resource(new Resource("Health", 0, 100));
	johannes->add_resource(new Resource("Mana", 0, 100));

	johannes->add_attribute(new Attribute("Strength", 17));
	johannes->add_attribute(new Attribute("Intelligence", 25));
	johannes->add_attribute(new Attribute("Sexyness", 10000));

	FullBehaviour* beh = new FullBehaviour();
	johannes->behaviour = beh;
	beh->add_ratio(new BehaviourRatio(OWNER, "Health", 2));
	beh->add_ratio(new BehaviourRatio(ENEMY, "Health", -1));
	
	johannes->add_ability(new AttackAbility());
	johannes->add_ability(new HealAbility());

    johannes->add_event(
			new EventCondition(OWNER, "Health", LESS_THAN, 50),
			new ActionDefinition(OWNER, OWNER, dynamic_cast<Ability*>(johannes->get_child("Heal"))));

	/*
	Ability* abil;

	abil = new Ability("Sexy", 0, 10);
	abil->add_child(new Effect(OWNER, TARGET, "Health", -20));
	abil->add_child(new Effect(OWNER, OWNER, "Health", 10));

	johannes->add_ability(abil);

	abil = new Ability("Attack", 0, 0);
	abil->effects.push_back(new Effect(OWNER, TARGET, "Health", -30));
	abil->add_rgr(ENEMY);
	abil->add_rgr(OWNER);

	johannes->add_ability(abil);

	abil = new Ability("Heal", 20, 0);
	abil->effects.push_back(new Effect(OWNER, TARGET, "Health", 30));
	abil->add_rgr(ENEMY);
	abil->add_rgr(OWNER);
	*/

	return johannes;
}

Character* make_biggi_clean()
{
    Character *biggi = new Character();
    biggi->name = "Biggi";
    
    // PrettyPrinter::print("Resources...\n", FG_YELLOW);
	biggi->add_resource(new Resource("Health", 0, 250));
	biggi->add_resource(new Resource("Mana", 0, 50));

	biggi->add_attribute(new Attribute("Strength", 50));
	biggi->add_attribute(new Attribute("Intelligence", 1));
	biggi->add_attribute(new Attribute("Sexyness", -5));
    
	// Behaviour
	biggi->behaviour = make_fighter_behaviour();

    // Abilities.
    // PrettyPrinter::print("Abilities...\n", FG_YELLOW);
    // biggi->add_ability("Maul", new AttackAbility());
	Ability* abil = new Ability("Maul", 0, 0);
	
	abil->add_child(new Effect(OWNER, TARGET, "Health", -10));
	biggi->add_ability(abil);

	return biggi;
}

GameState* make_base_state()
{
	GameState::register_identifier(new EnemyIdentifier());
    GameState::register_identifier(new OwnerIdentifier());
	GameState::register_identifier(new TargetIdentifier());

    GameState *state = new GameState();

	Character* joe = make_joe_clean();
	Character* big = make_biggi_clean();

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
	Character* johannes = make_joe_clean();
    johannes->pretty_print();

	Character* biggi = make_biggi_clean();
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
	game->add_child(make_joe_clean());
	Character *sex = make_joe_clean();
	sex->name = "Biggi";
	game->add_child(sex);
	game->run();

	game->current_state->pretty_print();

	/*** END TRUE ENGINE TEST ***/

	return 0;
}
