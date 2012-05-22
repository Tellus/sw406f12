/*
 * Team.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#ifndef TEAM_H_
#define TEAM_H_

#include <list>
#include <algorithm>

#include "Character.h"

namespace engine
{

/**
 * Your classic team. Used to differentiate between "us", "them" and "the other
 * guys". While we didn't really dig much into the whole team thin in langname,
 * it seemed a lot simpler for a generic method than having "first char" and
 * "second char" members in GameState.
 **/
class Team
{
public:
    /**
     * Creates a new team with a specific id.
     **/
    Team(int id);

	/**
	 * List of team members as Primarch IDs. These are much simpler to track
	 * across GameStates than pointers.
	 */
    std::list<int> members;
    
    /**
     * Identifier for the team. I'm not really into the whole "Fighting
     * Mongooses" thing. An integer id is sufficient.
     **/
    int id;
    
    /**
     * Adds a Character instance to this team.
     * \param to_add The Character to add.
     **/
    void add_character(Character *to_add);
    
    /**
     * Removes a Character from the Team.
     * I don't think you'd ever use this unless there's a Charm spell in play.
     * \param to_remove Reference to the Character to remove. The Character's
     * Id is used, not the pointer value. This is to ensure validity across
     * GameState copies.
     **/
    void remove_character(Character *to_remove);
    
    /**
     * Removes a Character from the Team.
     * Probably never used.
     * \param id The Primarch Id of the Character to remove.
     * \see remove_character(Character *to_remove)
     **/
    void remove_character(int id);
    
    /**
     * Checks to see if a Character is already on the team.
     * \param id The Primarch Id of the Character you're checking for.
     * \return True if the Character is on the Team, false otherwise.
     **/
    bool has_character(int id);

    /**
     * Retrieves the first Character pushed into the Team.
     * Proxy for members->front().
     **/
	int first_char();
};

}

#endif
