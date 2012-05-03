/*
 * Team.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

#include <list>
#include <algorithm>

#include "Character.h"

namespace engine
{

class Team
{
public:
	/**
	 * List of team members as Primarch IDs. These are much simpler to track across GameStates than
	 * pointers.
	 */
    std::list<int> members;
    
    Team(int id);
    
    int id;
    
    void add_character(Character *to_add);
    
    void remove_character(Character *to_remove);
    void remove_character(int id);
    
    bool has_character(int id);

	int first_char();
};

}
