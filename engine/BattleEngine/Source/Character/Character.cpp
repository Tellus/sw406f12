/*
 * Character.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Character.h"
#include "Exceptions/DuplicateKeyException.h"

namespace engine {

Character::Character()
{
	// TODO Auto-generated constructor stub
	this->name = "Noname";
	_init();
}

Character::~Character()
{
	// TODO Auto-generated destructor stub
}

Character::Character(const Character& copy)
{
    // TODO: Remaining things that must be copied.

    this->name = copy.name;
    
    // Abilities
    std::map<std::string, Ability*> abil_remote = copy.abilities;
    
    for (std::map<std::string, Ability*>::iterator abil_iter = abil_remote.begin();
         abil_iter != abil_remote.end();
         abil_iter++)
     {
        this->add_ability(abil_iter->first, new Ability(*abil_iter->second));
     }
    
    // Resources
    std::map<std::string, Resource*> res_remote = copy.resources;
    
    for (std::map<std::string, Resource*>::iterator res_iter = res_remote.begin();
         res_iter != res_remote.end();
         res_iter++)
     {
        this->add_resource(res_iter->first, new Resource(res_iter->second));
     }
    
    // Attributes
    std::map<std::string, Attribute*> attr_remote = copy.attributes;
    
    for (std::map<std::string, Attribute*>::iterator attr_iter = attr_remote.begin();
         attr_iter != attr_remote.end();
         attr_iter++)
     {
        this->add_attribute(attr_iter->first, new Attribute(attr_iter->second));
     }
}

void Character::_init()
{
    this->resources = std::map<std::string,Resource*>();
    this->abilities = std::map<std::string,Ability*>();
    this->attributes = std::map<std::string,Attribute*>();
}

void Character::pretty_print()
{
    std::cout << "Character: " << this->name;
    std::cout << "Attributes:\n";
    std::map<std::string,Attribute*> *tmp = &this->attributes;
    for (std::map<std::string,Attribute*>::iterator iter = tmp->begin(); iter != tmp->end(); iter++)
    {
        std::cout << '\t' << iter->first << '\t' << iter->second->get_current() << '\n';
    }
    std::cout << "Resources:\n";
    
    std::map<std::string,Resource*> *res = &this->resources;
    for (std::map<std::string,Resource*>::iterator iter = res->begin(); iter != res->end(); iter++)
    {
        std::cout << '\t' << iter->first << '\t' << iter->second->get_current() << '\n';
    }
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

void Character::add_ability(std::string name, Ability *abil)
{
    if (this->has_ability(name))
    {
		std::string tmp = "Character::resources already contains a key at " + name + ".";
		throw DuplicateKeyException(tmp);
    }
    else
    {
        this->abilities[name] = abil;
    }
}

std::map<std::string, Ability*> Character::get_abilities()
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

bool Character::has_ability(std::string name)
{
    return (this->abilities.count(name)>0);
}

} /* namespace engine */
