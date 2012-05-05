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
	// Get their team.
	int t_id = from->get_char_team(from->current_char);

	if (t_id == -1)
	{
		return NULL;
	}

	// Pointers are... much... cheaper, Joe.
	std::list<Team*> *teams = &from->teams;

	std::list<Team*>::iterator iter = teams->begin();

	for (;
		 iter != teams->end();
		 iter++)
	{
		if ((*iter)->id == t_id) continue; // Skip if the teams are identical. Enemies are not on your team.
		else
		{
			return from->get_character_by_id((*iter)->first_char());
		}
	}

	return NULL;
}

}
