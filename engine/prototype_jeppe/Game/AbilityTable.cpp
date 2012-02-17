/*
 * AbilityTable.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../Headers/AbilityTable.h"

using namespace std;

list<Action*> AbilityTable::generate(Character *source,
		list<Character*> characters, Ability *ability)
{
	list<Action*> actions;

	if (ability->id.compare("attack") == 0)
	{
		for (list<Character*>::iterator it = characters.begin();
				it != characters.end(); it++)
		{
			if ((*it) != source)
			{
				Action *action = new Action(source->name + " attacks " +
					(*it)->name + "!");

				action->add_effect(new PhysicalDamage(source, (*it), 10));

				actions.push_back(action);
			}
		}
	}

	return actions;
}

AbilityTable::AbilityTable() {
	// TODO Auto-generated constructor stub

}

AbilityTable::~AbilityTable() {
	// TODO Auto-generated destructor stub
}
