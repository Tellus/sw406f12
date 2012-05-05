/*
 * Engine.cpp
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#include "Engine.h"

namespace engine
{

Engine::Engine()
{
	this->_init();
}

Engine::Engine(WinCondition* win)
{
	this->_init();
	this->win_condition = win;
}

Engine::~Engine()
{
	delete this->current_state;
	delete this->win_condition;
}

void Engine::_init()
{
	this->win_condition = NULL;
	this->current_state = new GameState();

	this->current_state->register_identifier(new EnemyIdentifier());
	this->current_state->register_identifier(new OwnerIdentifier());
}

void Engine::add_character(Character* to_add)
{
	try
	{
		PrimarchIndexer::add_character(to_add);

		this->current_state->add_character(to_add);
		
		this->current_state->set_team_aff(this->current_state->max_team_id()+1, to_add);

		this->turn_order.push_back(to_add->id);
	}
	catch (std::exception e)
	{
		throw e;
	}
}

void Engine::add_character(Character* to_add, int team_id)
{
	this->add_character(to_add);

	this->current_state->set_team_aff(team_id, to_add);
}

Character* Engine::get_next_character()
{
	// this->current_turn++;
	if (this->current_turn == this->turn_order.end())
		this->current_turn = this->turn_order.begin();
	else
		this->current_turn++;
	if (this->current_turn == this->turn_order.end())
		this->current_turn = this->turn_order.begin();

	// Resolve character and return.
	return this->get_character_by_id(*(this->current_turn));
	// return this->current_state->get_character_by_id(*(this->current_turn));
}

void Engine::run()
{
	// Reset turn order.
	this->current_turn = this->turn_order.end();
	this->current_state->current_char = this->get_next_character();

	/**
	 * Engine cycle:
	 * 1. Check win condition (automatic).
	 * 2. Iterate character.
	 * 3. AbilityTable on the current char.
	 * 4. Replace current_state with best state from AbilityTable.
	 */

	AbilityTable *at;

	while (!this->win_condition->is_met(this->current_state))
	{
		/*
		std::cout << "*********************\n";
		std::cout << "Pre-execution state:\n";
		this->current_state->pretty_print();
		std::cout << "*********************\n";
		*/

		this->current_state->current_char = this->current_state->get_character_by_id(this->get_next_character()->id);

		Character* cur = this->current_state->current_char;
		/*
		std::cout << "*****\n";
		std::cout << cur->name << "[" << cur << "] (" << cur->get_resource("Health")->get_current() << "/" << cur->get_resource("Mana")->get_current() << ") ponders their next move.\n";
		std::cout << "*****\n";

		this->current_state->pretty_print();
		*/
		at = new AbilityTable(this->current_state);
    
		this->current_state = at->get_next_state();

		/*
		std::cout << "*********************\n";
		std::cout << "Post-execution state:\n";
		this->current_state->pretty_print();
		std::cout << "*********************\n";
		*/
	}

	std::cout << "Game over! Thanks for playing. Insert Coin.\n";
}

}