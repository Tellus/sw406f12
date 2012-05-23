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
#include "Resource.h"
#include "Behaviour.h"
#include "EventListener.h"

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

/**
 * The Character class is one of the representations of Primarchs from langname.
 * It works almost completely independantly of GameState, only relying on it for
 * piggy calculations.
 **/
class Character : public Primarch
{
public:
    /**
     * Creates a new, empty, Character. Quite, useless.
     **/
	Character();
	
	/**
	 * \todo Implement.
	 **/
	virtual ~Character();

    /**
     * Inherited from Primarch. Creates a complete clone of the Character with
     * all of its underlying Resource, Attributes and such.
     * \param with_id True if the clone is to be made as an exact copy of the
     * Character, false if you want it to work as a new, separate Character.
     * \return A new Character. Remember to cast it.
     **/
	virtual Primarch* clone(bool with_id);

    /**
     * Map(AttributeName,Attribute*) of Attributes.
     **/
	std::map<std::string, Attribute*> attributes;
	
	/**
	 * Map(ResourceName,Resource*) of Resources.
	 **/
	std::map<std::string, Resource*> resources;

    /**
     * Map(AbilityName, Ability*) of Abilities.
     **/
	std::map<std::string, Ability*> abilities;

    /**
     * Behaviour that defines how the Character should act on its turn.
     **/
	Behaviour* behaviour;

    /**
     * Adds a new Attribute to the Character.
     * \param name Key (and name) for the Attribute.
     * \param attribute Pointer to the Attribute to add.
     **/
	void add_attribute(std::string name, Attribute *attribute);
	
    /**
     * Adds a new Attribute to the Character. Uses the Attribute's own name to
     * map it.
     * \param attribute Pointer to the Attribute to add.
     **/	
	void add_attribute(Attribute* attribute);
	
	/**
	 * Add a new Resource to the Character.
	 * \param name Key and name for the Resource.
	 * \param resource Reference to the Resource object to add.
	 **/
	void add_resource(std::string name, Resource *resource);
	
	/**
	 * Add a new Resource to the Character. Uses the name of the Resource to
     * map it.
	 * \param resource Reference to the Resource object to add.
	 **/	
	void add_resource(Resource* resource);
	
	/**
	 * Adds an ability to the list of available abilities to the character.
	 * \param name The name of the Ability to add.
	 * \param abil The Ability to add.
	 **/
	void add_ability(std::string name, Ability *abil);

	/**
	 * Adds an ability to the list of available abilities to the character. The
	 * Ability's own name is used to map it.
	 * \param abil The Ability to add.
	 **/
	void add_ability(Ability* abil);
	
	/**
	 * Retrieves the Character's current piggy (happiness) value.
	 * \return The current piggy value.
	 * \note Mostly a proxy for Behaviour::get_piggy().
	 **/
	float get_piggy(GameState* from);
	
	/**
	 * Retrieves the ability list.
	 **/
	std::map<std::string, Ability*>* get_abilities();
	
	/**
	 * Retrieves the map of Attributes.
	 * \return Map<string,Attribute*) of the Attributes on the Character.
	 */
	std::map<std::string, Attribute*>* get_attributes();
	
	/**
	 * Retrieves the Character's Resource map.
	 **/
	std::map<std::string, Resource*>* get_resources();
	
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
	
	/**
	 * Checks for a named Ability on the Character.
	 * \param name Name of the Ability.
	 * \return True if the Ability is on the Character, false otherwise.
	 */
	bool has_ability(std::string name);
	
	/**
	 * Outputs the Character and all their data in a human-readable format to
	 * stdout.
	 **/
	virtual void pretty_print();
	
	/**
	 * List of EventCondition objects. These are iterated by the engine or
	 * GameState to check if any forced action should be taken instead of the
	 * default Behaviour method.
	 **/
	std::list<EventListener*> events;
	
	/**
	 * Adds a new EventListener to the Character.
	 * \param ec Listener to add.
	 **/
	void add_event(EventListener* ec);
	
	/**
	 * Retrieves all EventListeners attached to the Character.
	 * \return List of EventListeners.
	 **/
	std::list<EventListener*>* get_events();
	
	/**
	 * Adds a new event to the Character.
	 * \param condition Condition formatted as noted in
	 * EventCondition::EventCondition(std::string).
	 * \param def The ActionDefinition to bind it to.
	 **/
	void add_event(std::string condition, ActionDefinition* def);
	
	/**
	 * Adds a new event to the Character.
	 * \param ev EventCondition to bind to the Character.
	 * \param ad The ActionDefinition to bind it to.
	 **/
	void add_event(EventCondition* ev, ActionDefinition* ad);
	
	/**
	 * Returns the Character's current state. In typical hackish manner, this
	 * will typically return the value of the Resource "health".
	 **/
	float get_value();

    /**
     * Modifies the Character's current "value" (hackishly set as the health
     * Resource).
     **/ 
	void modify(float amount);
private:

    /**
     * Initializer method.
     **/
    void _init();
};

} /* namespace engine */
#endif /* CHARACTER_H_ */
