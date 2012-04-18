/*
 * GameState.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <list>

#include "Character.h"
#include "Behaviour.h"
#include "AbilityTable.h"
#include "Team.h"

#define GAMESTATE_CONTAINER_TYPE list

namespace engine {

class GameState {
public:
    /* CONSTRUCTORS */
	GameState();
	virtual ~GameState();
	
	/* MEMBERS */
	
	/** 
	 * Pointer to the character who is taking their turn.
	 **/
	Character *current_char;

	/**
	 * Vector of teams. Each team is another vector of Character pointers.
	 **/
	std::list<Team*> teams;
	
	/* METHODS */
	
	/**
	 * Vector of Character objects in-game. They are the essential core of
	 * changing the game state, as most changes affect them or spring from them.
	 **/
	std::list<Character*> characters;
	
	/**
	 * Copy constructor. Will copy the passed GameState into a new one, distinct
	 * from the original.
	 **/
    GameState(const GameState& copy);
    
    /**
     * Adds a character to the list of characters. Will use the pointer given
     * without copying.
     **/
    void add_character(Character *to_add);
    
    /**
     * Retrieves a pointer to a character represented by the passed RGR.
     * \param rgr The RGR to retrieve for.
     * \return Pointer to a Character in the GameState that represents the RGR.
     **/
    Character *get_rgr(RGR_Enum rgr);
};

} /* namespace engine */
#endif /* GAMESTATE_H_ */
