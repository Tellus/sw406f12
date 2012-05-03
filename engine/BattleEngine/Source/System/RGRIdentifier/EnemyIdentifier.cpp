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
	Character* cur = from->current_char;

	// frontend::PrettyPrinter::print("Trying to find an ENEMY for " + cur->name + '\n');

	// Get their team.
	int t_id = from->get_char_team(from->current_char);

	if (t_id == -1)
	{
		// frontend::PrettyPrinter::print_bad("The Character is not on a team. Cannot proceed!");
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
			return from->get_char_by_id((*iter)->first_char());
		}
	}

	// frontend::PrettyPrinter::print_bad("There are no valid ENEMY type Characters to be found.");
	return NULL;
}

}
