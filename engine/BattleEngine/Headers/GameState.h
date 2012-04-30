/*
 * GameState.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#pragma once

#include <list>
#include <string>
#include <iostream>

#include "RGRIdentifier.h"
#include "Character.h"
#include "Behaviour.h"
#include "Team.h"
#include "Exceptions/InvalidRGRException.h"

#include "PrettyPrinter.h"

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
     * Returns NULL if the RGR is invalid or not applicable (for example ALLY
     * if there are only two characters, OWNER and ENEMY).
     **/
    Character *get_rgr(RGR_Enum rgr);
    
    static std::map<RGR_Enum, RGRIdentifier*> rgr_identifiers;
    
    /**
     * Human-readable text output of the GameState's current data contents.
     **/
    void pretty_print();
    
    /**
     * Retrieves the Character identified by id, if any.
     * \param id The id to look for.
     * \return Pointer to the Character if found, null otherwise.
     **/
    Character *get_char_by_id(int id);
    
    static void register_identifier(RGRIdentifier *r);
};

} /* namespace engine */
