/*
 * Character.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Attribute.h"
#include "Ability.h"
#include "ContEffect.h"
#include "Resource.h"

#include <string>
#include <map>
#include <list>

namespace engine {

class Character {
protected:
    int id_counter;

public:
	std::map<std::string, Attribute*> attributes;
	std::map<std::string, Resource*> resources;
	std::list<ContEffect*> continuoos_effects;
	std::list<Ability*> abilities;

	void add_attribute(std::string name, Attribute *attribute);
	void add_resource(std::string name, Resource *resource);

    /**
     * Fuckin' arbitrary id. Assume that this id will be unique for this
     * Character among all Character instances in the active GameState.
     **/
    int id;

	Character();
	virtual ~Character();
};

} /* namespace engine */
#endif /* CHARACTER_H_ */
