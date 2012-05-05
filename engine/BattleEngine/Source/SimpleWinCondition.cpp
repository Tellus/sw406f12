#include "SimpleWinCondition.h"

namespace engine
{

SimpleWinCondition::SimpleWinCondition()
{
	// Why no implement?
}


SimpleWinCondition::~SimpleWinCondition()
{
	// Why no implement?
}

/**
 * Our simple win condition simply checks health resources.
 */
bool SimpleWinCondition::is_met(GameState* check)
{
	std::list<Team*> teams = check->teams;

	Character* tmp_c;

	// Loop teams.
	for (std::list<Team*>::iterator team_iter = teams.begin();
		 team_iter != teams.end();
		 team_iter++)
	{
		// Loop each char in team.
		for (std::list<int>::iterator char_iter = (*team_iter)->members.begin();
		 	char_iter != (*team_iter)->members.end();
		 	char_iter++)
		{
			tmp_c = check->get_character_by_id(*char_iter);

			if (tmp_c->get_resource("Health")->get_current() <= 0)
			{
				return true;
			}
		}
	}

	return false;
}

}