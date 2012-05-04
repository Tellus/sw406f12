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

	for (std::list<Team*>::iterator iter = teams.begin();
		 iter != teams.end();
		 iter++)
	{
		tmp_c = check->get_char_by_id((*iter)->id);
		if (tmp_c->get_resource("Health")->get_current() <= 0)
		{
			return true;
		}
	}

	return false;
}

}