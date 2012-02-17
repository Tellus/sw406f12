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
#include "Ability.h"
#include "Attribute.h"
#include "Resource.h"

using namespace std;

class Character {
public:
	list<Attribute*> attributes;
	list<Resource*> resources;
	list<Ability*> abilities;
	string name;

	Character();
	virtual ~Character();
};

#endif /* CHARACTER_H_ */
