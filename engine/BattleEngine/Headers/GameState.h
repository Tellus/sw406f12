/*
 * GameState.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef GAME_STATE_H_
#define GAME_STATE_H_

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

/**
 * The GameState is one of the more interesting pieces of software. It contains
 * a complete snapshot of a game in progress. In this regard it is
 * self-contained. AbilityTable and Engine makes use of GameStates as these
 * instant pics.
 **/
class GameState : public PrimarchIndexer
{
public:
    /* CONSTRUCTORS */
	GameState();
	virtual ~GameState();
	
	/**
	 * Clones the GameState. This is a clean, deep copy, i.e. any recognized
	 * pointer types (Primarch pointers, mostly) will be copied deep as well,
	 * instead of simply creating a new pointer pointing to the same object.
	 **/
	virtual GameState *clone();
	
	/** 
	 * Pointer to the character who is taking their turn.
	 **/
	Character *current_char;

	/**
	 * Vector of teams. Each team is another vector of Character pointers.
	 **/
	std::list<Team*> teams;
    
    /**
     * Retrieves a pointer to a character represented by the passed RGR.
     * \param rgr The RGR to retrieve for.
     * \return Pointer to a Character in the GameState that represents the RGR.
     * Returns NULL if the RGR is invalid or not applicable (for example ALLY
     * if there are only two characters, OWNER and ENEMY).
     **/
    Character *get_rgr(RGR_Enum rgr);
    
    /**
     * Map of all known RGRIdentifiers. Since it would be a terrible waste to 
     * duplicate these every friggin' time we create a new GameState, they're
     * kept statically. If you want to, you can create independant identifiers
     * with no ill effect, but they're here if you want them.
     **/
    static std::map<RGR_Enum, RGRIdentifier*> rgr_identifiers;
    
    /**
     * Outputs human-readable text output of the GameState's current data
     * contents to stdout.
     **/
    void pretty_print();
    
    /**
     * Statically register a new RGRIdentifier to the GameState.
     **/
    static void register_identifier(RGRIdentifier *r);

    /**
     * Sets the active TARGET. Since we aren't working with geometry or any
     * sense of movement, targetting a single Character is sufficient for our
     * purposes.
     * This call is essential to the working of the TargetIdentifier.
     * \param t Character to target.
     **/
	void set_target(Character* t);

    /**
     * Returns the currently targeted Character.
     * \return The Character currently the target.
     **/
	Character* get_target();

	// Sets a Character to be on a specific team. Vital for some RGRIdentifiers to work properly.
	/**
	 * Puts a Character into a specific Team.
	 * \param t_id Id of the Team. If the Team does not exist, it will be
	 * created.
	 * \param to_set The Character to place on the team.
	 * \return True if succesful, false otherwise.
	 **/
	bool set_team_aff(int t_id, Character* to_set);

    /**
     * Returns the Team Id that a Character is on.
     * \param c_id Primarch Id of the Character to find in a team.
     * \return The Team that the Character is on. -1 if not on a team.
     **/
	int get_char_team(int c_id);
	
    /**
     * Returns the Team Id that a Character is on.
     * \param c Character to find in a team. Uses the Character's Primarch Id.
     * \return The Team that the Character is on. -1 if not on a team.
     **/
	int get_char_team(Character* c);

	/**
	 * Gets the highest team id registered so far.
	 */
	int max_team_id();

protected:
    /**
     * Like current_character, denotes the Character being targeted by
     * current_char's Ability.
     **/
	Character* target_character;

private:
	/**
	 * Private initialization function.
	 */
	void _init();
};

} /* namespace engine */

#endif
