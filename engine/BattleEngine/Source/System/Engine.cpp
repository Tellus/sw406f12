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
	for (std::list<Character*>::iterator iter = this->base_characters.begin();
		iter != this->base_characters.end();
		iter++)
	{
		delete (*iter);
	}
}

void Engine::_init()
{
	this->win_condition = NULL;
	this->base_characters = std::list<Character*>();
	this->current_state = new GameState();
}

void Engine::add_character(Character* to_add)
{
	Character* copy = this->_add_base_char(to_add);

	if (this->current_state->get_char_by_id(copy->id) == NULL)
		this->current_state->add_character(copy);

	this->current_state->set_team_aff(this->current_state->max_team_id()+1, copy);
}

void Engine::add_character(Character* to_add, int team_id)
{
	Character* copy = this->_add_base_char(to_add);

	if (this->current_state->get_char_by_id(copy->id) == NULL)
		this->current_state->add_character(copy);

	this->current_state->set_team_aff(team_id, copy);
}

Character* Engine::_add_base_char(Character* to_add)
{
	// Make sure there are no doubles. Maybe a map would've been better.
	if (this->character_exists(to_add->id) || this->character_exists(to_add->name))
	{
		throw "Character already in collection.";
	}
	
	// Copy the input character, as promised.
	Character* clone = dynamic_cast<Character*>(to_add->clone(true));

	// Add to list of base chars.
	this->base_characters.push_back(clone);

	// Insert into turn order. We do this in a simple manner for now, although
	// a dedicated turn order class or function pointer should be defined.
	this->turn_order.push_back(clone->id);

	return clone;
}

bool Engine::character_exists(int c_id)
{
	std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->base_characters.begin(),
						  this->base_characters.end(),
						  [c_id](Character* cp){ return cp->id == c_id;});
    
    if (finder == this->base_characters.end()) return false;
    else return true;
}

bool Engine::character_exists(std::string name)
{
	std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->base_characters.begin(),
						  this->base_characters.end(),
						  [name](Character* cp){ return cp->name == name;});
    
    if (finder == this->base_characters.end()) return false;
    else return true;
}

Character* Engine::get_next_character()
{
	if (this->current_turn == this->turn_order.end())
	{
		// Start over at beginning.
		this->current_turn = this->turn_order.begin();
	}
	else
	{
		this->current_turn++;
	}

	// Resolve character and return.
	return this->get_character_by_id(*(this->current_turn));
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
	 // TODO: Turn order.
	 * 3. AbilityTable on the current char.
	 * 4. Replace current_state with best state from AbilityTable.
	 */

	while (!this->win_condition->is_met(this->current_state))
	{
		//this->current_state->current_char = 
	}
}

}