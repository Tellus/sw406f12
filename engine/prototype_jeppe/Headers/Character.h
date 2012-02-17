/*
 * Character.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <list>
#include <string>
#include <iostream>
#include "Abilities.h"
#include "Attribute.h"
#include "Resource.h"

using namespace std;

class Character {
public:
	list<Attribute*> attributes;
	list<Resource*> resources;
	list<Ability*> abilities;
	string name;
	bool dead;

	double attribute(string id);
	double resource(string id);
	void resource_deplete(string id, double amount, bool verbose);
	void turnover(bool verbose);

	Character();
	Character(string name, double health, double attack, double defense);
	virtual ~Character();
};

#endif /* CHARACTER_H_ */
