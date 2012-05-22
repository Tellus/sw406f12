/*
 * Engine.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <memory>

#include "PrimarchIndexer.h"
#include "GameState.h"
#include "Character.h"
#include "WinCondition.h"
#include "AbilityTable.h"

#include "EnemyIdentifier.h"
#include "OwnerIdentifier.h"
#include "TargetIdentifier.h"

namespace engine
{

/**
 * The engine wraps together all the framework elements into a simple, self-running
 * package. You supply it Characters and a WinCondition object (subclasses), and the
 * rest should easily be handled by the cookie-cutter world.
 */
class Engine : public PrimarchIndexer
{
public:
	Engine();
	Engine(WinCondition* win);
	virtual ~Engine();

	/**
	 * At all times, this will be a pointer to the current state of the game.
	 * It will change rapidly depending on the execution speed of AI turns.
	 */
	GameState* current_state;

	/**
	 * The active win condition. This is tested after each turn cycle to see if
	 * the cycle should be broken.
	 */
	WinCondition* win_condition;

	/**
	 * Vector of Primarch IDs corresponding to Characters and their turn.
	 **/
	std::vector<int> turn_order;

	/**
	 * Iterator from turn_order that denotes where we are in the turn order.
	 * Dereferenced for current_car->id, iterated around turn_order to maintain
	 * sequencial order.
	 **/
	std::vector<int>::iterator current_turn;

	/**
	 * Adds another Character to the roster, on a new team (i.e. ENEMy to all).
	 * \param to_add Character to add.
	 * \note This method CLONES the Character, leaving the original untouched.
	 */
	void add_child(Primarch* to_add);

	/**
	 * Proxy call with more type safty for add_child(Primarch*).
	 **/
	void add_child(Character* to_add);

	/**
	 * Adds another Character ot the roster, on a specific team.
	 * \param to_add The Character to add.
	 * \note This method CLONES the Character.
	 */
	void add_character(Character* to_add, int team_id);

	/**
	 * Checks to see if the passed Character (by Primarch ID) is present in either
	 * the list of base characters or the current GameState.
	 * \param c_id The ID of the Character to look for.
	 * \return True if the Character was found, false otherwise.
	 */
	bool character_exists(int c_id);

	/**
	 * Runs until a win condition is encountered.
	 */
	void run();
	
	/**
	 * Performs a single Character turn and stops.
	 * \return Action object that represents the action taken by the Character.
	 **/
	Action* step();

	/**
	 * Iterates the turn counter and returns the Character who is
	 * up next.
	 */
	Character* get_next_character();

protected:
	/**
	 * Harvests events from the underlying current state's Primarch objects.
	 **/
	void harvest_events();

	/**
	 * Raises all pending events.
	 **/
	void raise_events();

	/**
	 * Complete list of all events that have not been raised since the last
	 * execution loop.
	 **/
	std::list<GameEvent*> pending_events;

	/**
	 * A complete mapping (EVENT_TYPE -> [Primarch*]) of which event types
	 * have been registered to specific callback functions.
	 **/
	std::map<std::string, std::list<callback> > registered_event_listeners;

	void get_callbacks();

private:
	Character* _add_base_char(Character* to_add, int team_id = -1);
	void _init(void);
};

}

namespace generated
{
	void run();
}

#endif
