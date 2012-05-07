/*
 * GameEvent.cpp
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */

#include "GameEvent.h"

namespace engine {

GameEvent::GameEvent()
{
	// TODO Auto-generated constructor stub
	this->_running = false;
}

GameEvent::~GameEvent()
{
	// TODO Auto-generated destructor stub
}

void GameEvent::add_listener(void* object, game_event_fp callback_f)
{
	if (this->_running)
		throw EventLockedException("The Event is running and listeners cannot be modified.");

	this->listeners.push_back(callback(object, callback_f));
}

void GameEvent::raise()
{
	this->_running = true;

	for (this->current_listener = this->listeners.begin();
		this->current_listener != this->listeners.end();
		this->current_listener++)
	{
		game_event_fp fp = this->current_listener->second;
		GameEvent *to_send = this;
		fp(to_send);
	}

	this->_running = false;
}

void GameEvent::cancel()
{
	this->current_listener = this->listeners.end();
}

std::string GameEvent::get_type()
{
	return this->_event_type;
}

void GameEvent::set_type(std::string new_type)
{
	this->_event_type = new_type;
}

} /* namespace engine */
