/*
 * Primarch.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#ifndef PRIMARCH_H_
#define PRIMARCH_H_

#include <iostream>
#include <string>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include "GameEvent.h"
#include "Exceptions/PrimarchDoesNotExistException.h"

namespace engine {

/**
 * The Primarch represents a base class for many of the classes in the Character
 * part of our system... or a stupid way to resolve a circular dependancy.
 **/
class Primarch
{
public:
    /**
     * Creates a new *unique* Primarch for the Engine.
     **/
    Primarch();
    
    /**
     * Creates a new Primarch with a human-readable name. Similar
     * to base constructor in its workings.
     **/
    Primarch(std::string name);

    virtual ~Primarch();

	/**
	 * Clones the Primarch into an identical (with regard to the type) copy.
	 * \param with_id Create with existing id? Consider this the difference
	 * between carbon copy (where both copies are, for all intents and purposes -
	 * except pointers - identical) and twins (where they are identical, but
	 * distinct). Consider the difference between creating an identical character
	 * (where the id should NOT be identical) for convenience or cloning the
	 * character during the GameState cloning procedure (where even the id
	 * needs to be identical).
	 */
	virtual Primarch* clone(bool with_id = false) = 0;

    /**
     * Global Id for a primarch. This is identical across GameState making it
     * simpler to follow the "same" object through several instances.
     **/
    int id;
    
    /**
     * Name. basically everything has a meaningful name. So, centralized :D
     **/
    std::string name;
    
    /**
     * Pretty print. Should print human-readable information about the
     * subclass instance.
     **/
    virtual void pretty_print() = 0;
    
    /**
     * Generates (... iterates) a new global identifier value.
     * \return a guaranteed unique id.
     **/
    static long get_new_id();
    
    /**
     * Retrieves any pending events in the Primarch and flushes the internal
     * list.
     * \return A list of GameEvent pointers.
     * \note The list must be used. The internal pointer list is flushed with
     * the call.
     **/
    std::list<GameEvent*> get_pending_events();

	/**
	 * Should return a list of any callbacks that the object is interested in.
	 * For example, this should for a Character Primarch return callbacks for
	 * RESOURCE_DECREASE and the like.
	 **/
	std::map<std::string, std::list<callback>> get_callbacks();
	
	/**
	 * Should return a float value representing the current value of the Primarch.
	 * For Resource and Attribute, this is most likely current. For the rest...
	 * well ... I'm up for votes!
	 **/
	virtual float get_value() = 0;

	/**
	 * Adds a child Primarch.
	 **/
    void add_child(Primarch* c);
    
	/**
	 * Removes a child Primarch.
	 **/
    void remove_child(Primarch* c);
    
	/**
	 * Removes a child Primarch.
	 **/
    void remove_child(int i);

	/**
	 * Checks to see if a child exists in the Primarch.
	 * \param i Primarch ID of the Child to find.
	 * \param go_deep True if the search should recurse into each child if not
	 * found.
	 * \note This is a breadth-first search.
	 **/
    bool has_child(int i, bool go_deep = false);

	bool has_child(std::string name, bool deep = false);

    /**
     * Retrieves a child Primarch from the object.
     * \param c_id The Primarch ID of the child to retrieve.
     * \param deep True if this should be performed as a full depth
     * breadth-first search.
     **/
    Primarch* get_child(int c_id, bool deep = false);

	Primarch* get_child(std::string name, bool deep = false);

	const std::list<Primarch*>* get_children();
protected:

	std::map<std::string, std::list<callback>> _callbacks;

    /**
     * List of events waiting to be raised.
     **/
    std::list<GameEvent*> pending_events;
    
    /**
     * List of child Primarchs connected to this one. Typically, this is a
     * question of various subclasses connected to a Character. While the
     * Character maintains separate lists for various types, Children is a
     * catch-all, meant for event traversal and other generic/global actions.
     **/
    std::list<Primarch*> children;

    void raise_event(std::string type);

	/**
	 * Creates a new name for the Primarch, in case non was suggested.
	 * \param type The type of the subclass ("Resource", for example).
	 * \return A string in the basic form ("<type>_<id>").
	 **/
	std::string get_default_name(std::string type);
private:
    static long _id_counter;
};

}

#endif
