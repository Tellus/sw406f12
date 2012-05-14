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
		// TODO: Add event condition handling.

		/*
		std::cout << "*********************\n";
		std::cout << "Pre-execution state:\n";
		this->current_state->pretty_print();
		std::cout << "*********************\n";
		*/

		this->current_state->current_char = dynamic_cast<Character*>(this->current_state->get_child_by_id(this->get_next_character()->id));

		// Character* cur = this->current_state->current_char;
		/*
		std::cout << "*****\n";
		std::cout << cur->name << "[" << cur << "] (" << cur->get_resource("Health")->get_current() << "/" << cur->get_resource("Mana")->get_current() << ") ponders their next move.\n";
		std::cout << "*****\n";

		this->current_state->pretty_print();
		*/
		at = new AbilityTable(this->current_state);
    
		// TODO: There's a malign health calculation here!
		this->current_state = at->get_next_state();

		std::cout << this->current_state->current_char->name << " used " << at->best_action->action_def.ability->name << " on " << RGR_List::to_string(at->best_action->action_def.target) << ".\n";

		std::cout << "*********************\n";
		std::cout << "Post-execution state:\n";
		this->current_state->pretty_print();
		std::cout << "*********************\n";
	}

	std::cout << "Game over! Thanks for playing. Insert Coin.\n";
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

void Engine::get_callbacks()
{
	// Opposed to raised events, callbacks are more persistent.
	// We can't simply purge the list every time, but must construct
	// one hiarchially...billy...silly.

	// We do start, however, by emptying it. We're working one-offs right now.
	this->registered_event_listeners.clear();

	for (std::list<Primarch*>::iterator iter = this->children.begin();
		 iter != this->children.end();
		 iter++)
	{
		std::map<std::string, std::list<callback>> tmp = (*iter)->get_callbacks();
		for (std::map<std::string, std::list<callback>>::iterator cb_iter = tmp.begin();
			 cb_iter != tmp.end();
			 cb_iter++)
		{
			this->registered_event_listeners[(*cb_iter).first].merge((*cb_iter).second);
		}
	}
}

}
