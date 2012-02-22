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
	Action *action;

	for (list<Ability::target>::iterator it = ability->targets.begin();
			it != ability->targets.end(); it++)
	{
		switch(*it)
		{
		case Ability::self:
			action = new Action(this->generate_output(
					ability->output, source->name, source->name));
			action->effects.push_back(this->generate_effect(source, source,
															ability->id));
			actions.push_back(action);
			break;
		case Ability::enemy:
			for (list<Character*>::iterator jt = characters.begin();
					jt != characters.end(); jt++)
			{
				if ((*jt) != source)
				{
					action = new Action(this->generate_output(
							ability->output, source->name, (*jt)->name));
					action->effects.push_back(this->generate_effect(source,
														(*jt), ability->id));
					actions.push_back(action);
				}
			}
			break;
		default:
			break;
		}
	}

	return actions;
}

Effect *AbilityTable::generate_effect(Character *source, Character *target,
									  string id)
{
	if (id.compare("attack") == 0)
	{
		return new PhysicalDamage(source, target, 10);
	}
	else if (id.compare("heal") == 0)
	{
		return new InstantHeal(source, target, 25);
	}

	return NULL;
}

string AbilityTable::generate_output(string base, string source, string target)
{
	size_t pos;
	pos = base.find("{s}");
	if (pos != string::npos)
		base.replace(pos, 3, source);
	pos = base.find("{t}");
	if (pos != string::npos)
		base.replace(pos, 3, target);

	return base;
}

AbilityTable::AbilityTable() {
	// TODO Auto-generated constructor stub

}

AbilityTable::~AbilityTable() {
	// TODO Auto-generated destructor stub
}
