/*
 * Character.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Character.h"
#include "Exceptions/DuplicateKeyException.h"

namespace engine {

Character::Character() {
	// TODO Auto-generated constructor stub

}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

float Character::get_piggy()
{
    return this->behaviour.get_piggy();
}

std::map<std::string, Attribute*> Character::get_attributes()
{
	return this->attributes;
}

void Character::add_resource(std::string name, Resource *res)
{
	if (this->has_resource(name))
		throw new DuplicateKeyException("Character::resources already contains a key at " + name + ".");
	else
	{
		this->resources[name] = res;
	}
}

void Character::add_attribute(std::string name, Attribute *att)
{
	if (this->has_attribute(name))
	{
		std::string tmp = "Character::attributes already contains a key at " + name + ".";
		throw DuplicateKeyException(tmp);
	}
	else
	{
		this->attributes[name] = att;
	}
}

std::list<Ability*> Character::get_abilities()
{
	return this->abilities;
}

Resource* Character::get_resource(std::string name)
{
	if (this->has_resource(name)) return this->resources[name];
	else return NULL;
}

Attribute* Character::get_attribute(std::string name)
{
	if (this->has_attribute(name)) return this->attributes[name];
	else return NULL;
}

bool Character::has_attribute(std::string name)
{
	return (this->attributes.count(name)>0);
}

bool Character::has_resource(std::string name)
{
	return (this->resources.count(name)>0);
}

} /* namespace engine */
