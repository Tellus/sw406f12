/*
 * GameEvent.h
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */

#pragma once

#include <list>
#include <utility>

#include "Exceptions/EventLockedException.h"

namespace engine {

// Short-lived forward dec, so we can get the self-referencing typedef.
class GameEvent;

/**
 * Typedef of standard game event function pointers.
 **/
typedef void (*game_event_fp)(GameEvent*);

typedef std::pair<void*, game_event_fp> callback;

class GameEvent
{
public:
	GameEvent();
	virtual ~GameEvent();

	/**
	 * Pointer to the object that caused the event. Note that while the GameState will
	 * actually collect and propagate the event, the caller is rather the object
	 * that caused the GameState to do so. When a Character's Health Resource drops,
	 * for example, it will signal the GameState with either a PrimarchEvent (base),
	 * ResourceEvent (for the Resource class) or a HealthResourceEvent (bottom). Note
	 * that all three are hierarchially connected in the same way that Primarchs,
	 * Resources and Health is.
	 * Another important note: since we cannot know in advance the type of caller,
	 * we're forced to use a void pointer. Only attempt to cast and deference if you
	 * know what you're getting (for example, from specific subclasses of event).
	 **/
	void* caller;

	/**
	 * List of all registered listeners for this event.
	 **/
	std::list<std::pair<void*, game_event_fp>> listeners;

	/**
	 * The listener currently being invoked.
	 **/
	std::list<std::pair<void*, game_event_fp>>::iterator current_listener;

	/**
	 * Adds another listener object to the list. This method is *locked* once event
	 * resolution starts.
	 **/
	void add_listener(void* object, game_event_fp callback_f);

	/**
	 * Starts execution of the event.
	 **/
	void raise();

	/**
	 * Halts further execution of the event.
	 **/
	void cancel();

private:
	bool _running;
};

} /* namespace engine */
