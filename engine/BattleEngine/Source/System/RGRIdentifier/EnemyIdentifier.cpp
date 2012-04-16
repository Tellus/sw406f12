/*
 * EnemyIdentificer.cpp
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#include "EnemyIdentifier.h"

namespace engine
{

EnemyIdentifier::EnemyIdentifier()
{
    this->rgr = ENEMY;
}

Character *EnemyIdentifier::identify(GameState *from)
{
    std::list<Team*>::iterator iter;
    std::list<Team*> teams = from->teams;
    
    for (iter = teams.begin(); iter != teams.end(); iter++)
    {
        Team *tmp = *iter;
        if (!tmp->has_character(from->current_char->id))
        {
            return tmp->front();
        }
    }
    throw 404;
}

}
