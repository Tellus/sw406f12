/*
 * EnemyIdentificer.cpp
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#include "EnemyIdentifier_Unsafe.h"

namespace engine
{

EnemyIdentifier_Unsafe::EnemyIdentifier_Unsafe()
{
    this->rgr = ENEMY;
}

Character *EnemyIdentifier_Unsafe::identify(GameState *from)
{
    std::list<Team*>::iterator iter;
    std::list<Team*> teams = from->teams;
    
    for (iter = teams.begin(); iter != teams.end(); iter++)
    {
        Team *tmp = *iter;
        if (!tmp->has_character(from->current_char->id))
        {
			return dynamic_cast<Character*>(from->get_child_by_id(tmp->first_char()));
        }
    }

	return from->current_char;

    return NULL;
}

}
