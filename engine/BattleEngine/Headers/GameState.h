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
#include <limits>

#include "PrimarchIndexer.h"
#include "RGRIdentifier.h"
#include "Character.h"
#include "Behaviour.h"
#include "Team.h"
#include "Exceptions/InvalidRGRException.h"

#include "PrettyPrinter.h"

#define GAMESTATE_CONTAINER_TYPE list

namespace engine {

// TODO: Replace the character list with the PrimarchIndexer class as a base instead.

class GameState : public PrimarchIndexer
{
public:
    /* CONSTRUCTORS */
	GameState();
	virtual ~GameState();
	
	virtual GameState *clone();

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
    
    static void register_identifier(RGRIdentifier *r);

private:
	/**
	 * Private initialization function.
	 */
	void _init();
public:
	// Sets a Character to be on a specific team. Vital for some RGRIdentifiers to work properly.
	bool set_team_aff(int t_id, Character* to_set);
	// Finds the team that the Character is on, if any.
	int get_char_team(int c_id);
	int get_char_team(Character* c);

	/**
	 * Gets the highest team id registered so far.
	 */
	int max_team_id();
};

} /* namespace engine */
