/*
 * GameState.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <vector>

#include "Character.h"
#include "Behaviour.h"
#include "AbilityTable.h"

namespace engine {

class GameState {
public:
	GameState();
	virtual ~GameState();
	
	/**
	 * Vector of Character objects in-game. They are the essential core of
	 * changing the game state, as most changes affect them or spring from them.
	 **/
	std::vector<Character*> characters;
	
	/**
	 * Copy constructor. Will copy the passed GameState into a new one, distinct
	 * from the original.
	 **/
    GameState(const GameState& copy);
    
    /**
     * Creates a new empty GameState.
     **/
    GameState();
    
    /**
     * Adds a character to the list of characters. Will use the pointer given
     * without copying.
     **/
    void add_character(Character *to_add);
    
    /**
     * Copies a character into the GameState, leaving the original unaffected.
     **/
    void add_character_by_copy(const Character& copy);
};

} /* namespace engine */
#endif /* GAMESTATE_H_ */
