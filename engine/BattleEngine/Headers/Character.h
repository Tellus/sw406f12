/*
 * Character.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Primarch.h"
#include "Attribute.h"
#include "Ability.h"
#include "ContEffect.h"
#include "Resource.h"
#include "Behaviour.h"

#include <string>
#include <map>
#include <list>

namespace engine {

class Character : public Primarch
{
protected:
    int id_counter;

public:
    /** Membesr analogous to InvaderScript implementation. **/
	std::map<std::string, Attribute*> attributes;
	std::map<std::string, Resource*> resources;
	std::list<ContEffect*> continuoos_effects;
	std::list<Ability*> abilities;
	Behaviour behaviour;

    /**
     * Adds a new Attribute to the Character.
     * \param name Key (and name) for the Attribute.
     * \param attribute Pointer to the Attribute to add.
     **/
	void add_attribute(std::string name, Attribute *attribute);
	
	/**
	 * Add a new Resource to the Character.
	 * \param name Key and name for the Resource.
	 * \param resource Reference to the Resource object to add.
	 **/
	void add_resource(std::string name, Resource *resource);
	
	/**
	 * Retrieves the Character's current piggy (happiness) value.
	 * \return The current piggy value.
	 * \note Mostly a proxy for Behaviour::get_piggy().
	 **/
	float get_piggy();

    /**
     * Fuckin' arbitrary id. Assume that this id will be unique for this
     * Character among all Character instances in the active GameState.
     **/
    int id;

	Character();
	Character(const Character& copy);
	virtual ~Character();
	
	/**
	 * Retrieves a non-modifiable version of the ability list.
	 **/
	std::list<Ability*> get_abilities();
	
	/**
	 * Retrieves a resource on the character.
	 * \param name Name of the resource.
	 **/
	float get_resource(char *name);
	
	/**
	 * Retrieves a resource on the character.
	 * \param name Name of the resource.
	 **/
	float get_resource(std::string name);
	
	/**
	 * Retrieves an Attribute on the Character (if defined).
	 * \param name Name of the Attribute to retrieve.
	 **/
	float get_attribute(char *name);
	
	/**
	 * Retrieves an Attribute on the Character (if defined).
	 * \param name Name of the Attribute to retrieve.
	 **/
	float get_attribute(std::string name);
};

} /* namespace engine */
#endif /* CHARACTER_H_ */
