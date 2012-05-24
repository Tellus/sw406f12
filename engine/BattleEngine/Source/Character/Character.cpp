/*
 * Character.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Character.h"

namespace engine {

Character::Character()
{
	this->name = "Noname";
}

Character::~Character()
{
	// TODO Auto-generated destructor stub
}

Primarch *Character::clone(bool with_id = true)
{
	Character *new_char = new Character();

    new_char->name = this->name;
	if (with_id) new_char->id = id;
    
    // Abilities
    std::map<std::string, Ability*> abil_remote = this->abilities;
    
    for (std::map<std::string, Ability*>::iterator abil_iter = abil_remote.begin();
         abil_iter != abil_remote.end();
         abil_iter++)
     {
        new_char->add_ability(abil_iter->first, dynamic_cast<Ability*>(abil_iter->second->clone(true)));
     }
    
    // Resources
    std::map<std::string, Resource*> res_remote = this->resources;
    
    for (std::map<std::string, Resource*>::iterator res_iter = res_remote.begin();
         res_iter != res_remote.end();
         res_iter++)
     {
		new_char->add_resource(res_iter->first, dynamic_cast<Resource*>(res_iter->second->clone(true)));
     }
    
    // Attributes
    std::map<std::string, Attribute*> attr_remote = this->attributes;
    
    for (std::map<std::string, Attribute*>::iterator attr_iter = attr_remote.begin();
         attr_iter != attr_remote.end();
         attr_iter++)
    {
        new_char->add_attribute(attr_iter->first, dynamic_cast<Attribute*>(attr_iter->second->clone(true)));
    }	

	// Behaviour
	new_char->behaviour = this->behaviour->clone();

	return new_char;
}

void Character::pretty_print()
{
    std::cout << "Character(" << this << "): " << this->name << '\n';
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
    
    std::cout << "Abilities:\n";
    
    std::map<std::string,Ability*> *ab = &this->abilities;
    for (std::map<std::string,Ability*>::iterator iter = ab->begin(); iter != ab->end(); iter++)
    {
        iter->second->pretty_print();
    }
}

void Character::add_resource(std::string name, Resource *res)
{
	if (this->has_resource(name))
		throw DuplicateKeyException("Character::resources already contains a key at " + name + ".");
	else
	{
		this->resources[name] = res;
		this->add_child(res);
	}
}

void Character::add_resource(Resource* res)
{
    this->add_resource(res->name, res);
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
		this->add_child(att);
	}
}

void Character::add_attribute(Attribute* att)
{
    this->add_attribute(att->name, att);
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
		this->add_child(abil);
    }
}

void Character::add_ability(Ability *abil)
{
    this->add_ability(abil->name, abil);
}

void Character::add_event(EventListener* ec)
{
    this->events.push_back(ec);
}

std::map<std::string, Ability*>* Character::get_abilities()
{
	return &this->abilities;
}

std::map<std::string, Resource*>* Character::get_resources()
{
    return &this->resources;
}

std::map<std::string, Attribute*>* Character::get_attributes()
{
	return &this->attributes;
}


Resource* Character::get_resource(std::string name)
{
	if (this->has_resource(name)) return this->resources[name];
	else
	{
	    std::cout << "Resource '" << name << "' not found on char '" << this->name << "'\n";
		throw new ResourceDoesNotExistException("The requested resource does not exist.");
	}
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

float Character::get_piggy(GameState* from)
{
	return this->behaviour->get_piggy(from);
}

void Character::add_event(std::string ev, ActionDefinition* ac)
{
    this->events.push_back(new EventListener(new EventCondition(ev), ac));
}

void Character::add_event(EventCondition* ev, ActionDefinition* ac)
{
    this->events.push_back(new EventListener(ev, ac));
}

std::list<EventListener*>* Character::get_events()
{
    return &(this->events);
}

float Character::get_value()
{
	return this->get_resource("health")->get_current();
}

void Character::modify(float amount)
{
	// Does absolutely nothing.
}

} /* namespace engine */
