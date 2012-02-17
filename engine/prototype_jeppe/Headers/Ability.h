/*
 * Ability.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef ABILITY_H_
#define ABILITY_H_

#include <list>
#include <string>

using namespace std;

class Ability {
public:
	enum target
	{
		self,
		enemy,
		ally,
		team_enemy,
		team_ally
	};

	string id;
	list<target> targets;

	Ability();
	virtual ~Ability();
};

#endif /* ABILITY_H_ */
