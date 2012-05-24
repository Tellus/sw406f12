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
	this->current_state->register_identifier(new TargetIdentifier());
}

void Engine::add_child(Primarch* to_add)
{
	try
	{
		PrimarchIndexer::add_child(to_add);

		this->current_state->add_child(to_add);
		
		this->current_state->set_team_aff(this->current_state->max_team_id()+1, dynamic_cast<Character*>(to_add));

		this->turn_order.push_back(to_add->id);
	}
	catch (std::exception e)
	{
		throw e;
	}
}

void Engine::add_child(Character* to_add)
{
	this->add_child(dynamic_cast<Primarch*>(to_add));
}

void Engine::add_character(Character* to_add, int team_id)
{
	this->add_child(to_add);

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
	return dynamic_cast<Character*>(this->get_child_by_id(*(this->current_turn)));
}

void Engine::add_character(Character* to_add)
{
    int new_id = this->current_state->max_team_id()+1;
    this->add_character(to_add, new_id);
}

void Engine::init_game()
{
	this->current_turn = this->turn_order.end();
	this->current_state->current_char = this->get_next_character();
}

void Engine::run()
{
	// Reset turn order.
    this->init_game();

    std::cout << "Welcome to the battle. Let's see the contestants:\n";
    this->current_state->pretty_print();

	/**
	 * Engine cycle:
	 * 1. Check win condition (automatic).
	 * 2. Iterate character.
	 * 3. AbilityTable on the current char.
	 * 4. Replace current_state with best state from AbilityTable.
	 */

    Action* last_action;

	while (!this->win_condition->is_met(this->current_state))
	{
        last_action = this->step();

        std::cout << this->current_state->current_char->name
                  << " used "
                  << last_action->action_def.ability->name
                  << " on "
                  << RGR_List::to_string(last_action->action_def.target)
                  << ".\n";
        this->current_state->pretty_print();
	}

	std::cout << "Game over! Thanks for playing. Insert Coin.\n";
}

Action* Engine::step()
{
    AbilityTable* at;

    this->current_state->current_char = dynamic_cast<Character*>(
        this->current_state->get_child_by_id(
            this->get_next_character()->id));

    at = new AbilityTable(this->current_state);

    this->current_state = at->get_next_state();

    return at->best_action->clone();
}

void Engine::harvest_events()
{
	for (std::list<Primarch*>::iterator p_iter = this->current_state->children.begin();
		 p_iter != this->current_state->children.end();
		 p_iter++)
	{
		this->pending_events.merge((*p_iter)->get_pending_events());
	}

	// Done!
}

void Engine::raise_events()
{
	std::string event_type;

	for (std::list<GameEvent*>::iterator ge_iter = this->pending_events.begin();
		 ge_iter != this->pending_events.end();
		 ge_iter++)
	{
		// Populate with recipients of event type.
		event_type = (*ge_iter)->get_type();
		if (this->registered_event_listeners.count(event_type) > 0)
		{
			// We actually have hits :D
			for (std::list<callback>::iterator c_iter = this->registered_event_listeners[event_type].begin();
				 c_iter != this->registered_event_listeners[event_type].end();
				 c_iter++)
			{
				(*ge_iter)->add_listener((*c_iter).first, (*c_iter).second);
			}
		}
		// Send off.
		(*ge_iter)->raise();
	}

	// Kill.
	this->pending_events.clear();
}

}
