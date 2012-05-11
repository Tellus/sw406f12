/*
 * Character.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

// The necessities.
#include "Primarch.h"
#include "Attribute.h"
#include "Ability.h"
#include "ContEffect.h"
#include "Resource.h"
#include "Behaviour.h"
#include "ActionDefinition.h"
#include "EventCondition.h"

// The exceptions.
#include "Exceptions/ResourceDoesNotExistException.h"
#include "Exceptions/DuplicateKeyException.h"

// The built-ins.
#include <string>
#include <map>
#include <list>
#include <utility>

namespace engine {

typedef std::pair<EventCondition*, ActionDefinition*> event_action_pair;

// Forward declaration... hm.
class GameState;

class Character : public Primarch
{
protected:
    int id_counter;

public:
	Character();
	virtual ~Character();

	virtual Primarch* clone(bool with_id);

    /** Membesr analogous to InvaderScript implementation. **/
	std::map<std::string, Attribute*> attributes;
	std::map<std::string, Resource*> resources;

	std::map<std::string, Ability*> abilities;

    /**
     * Continuous effects. Unused.
     **/
	std::list<ContEffect*> cont_effects;
	Behaviour* behaviour;

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
	 * Adds an ability to the list of available abilities to the character.
	 **/
	void add_ability(std::string name, Ability *abil);
	
	/**
	 * Retrieves the Character's current piggy (happiness) value.
	 * \return The current piggy value.
	 * \note Mostly a proxy for Behaviour::get_piggy().
	 **/
	float get_piggy(GameState* from);
	
	/**
	 * Retrieves the ability list.
	 **/
	std::map<std::string, Ability*> get_abilities();
	
	/**
	 * Retrieves the map of Attributes.
	 * \return Map<string,Attribute*) of the Attributes on the Character.
	 */
	std::map<std::string, Attribute*> get_attributes();
	
	/**
	 * Retrieves a resource on the character.
	 * \param name Name of the resource.
	 **/
	Resource* get_resource(std::string name);
	
	/**
	 * Retrieves an Attribute on the Character (if defined).
	 * \param name Name of the Attribute to retrieve.
	 **/
	Attribute* get_attribute(std::string name);
	
	/**
	 * Checks for a named Attribute on the Character.
	 * \param name Name of the Attribute.
	 * \return True if the Attribute is on the Character, false otherwise.
	 */
	bool has_attribute(std::string name);
	
	/**
	 * Checks for a named Resource on the Character.
	 * \param name Name of the Resource.
	 * \return True if the Resource is on the Character, false otherwise.
	 */
	bool has_resource(std::string name);
	
	bool has_ability(std::string name);
	
	virtual void pretty_print();
	
	/**
	 * List of EventCondition objects. These are iterated by the engine or
	 * GameState to check if any forced action should be taken instead of the
	 * default Behaviour method.
	 **/
	std::list<event_action_pair> event_conditions;
	
	/**
	 * Adds a new event to the Character.
	 * \param condition Condition formatted as noted in EventCondition::EventCondition(std::string).
	 * \param def The ActionDefinition to bind it to.
	 **/
	void add_event(std::string condition, ActionDefinition* def);
	
	void add_event(EventCondition ev, ActionDefinition ad);
	
private:
    void _init();
};

} /* namespace engine */
#endif /* CHARACTER_H_ */
