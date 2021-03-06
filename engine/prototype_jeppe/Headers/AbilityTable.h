/*
 * AbilityTable.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef ABILITYTABLE_H_
#define ABILITYTABLE_H_

#include <list>
#include <string>
#include "Action.h"
#include "Ability.h"
#include "Character.h"
#include "Effects.h"

using namespace std;

class AbilityTable {
public:
	list<Action*> generate(Character *source, list<Character*> characters,
			Ability *ability);
	Effect *generate_effect(Character *source, Character *target, string id);
	string generate_output(string base, string source, string target);

	AbilityTable();
	virtual ~AbilityTable();
};

#endif /* ABILITYTABLE_H_ */
