/*
 * Primarch.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include <iostream>
#include <string>

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
    static int get_new_id();
    
private:
    static int _id_counter;
};

}
