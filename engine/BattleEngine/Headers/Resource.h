/*
 * Resource.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Attribute.h"

namespace engine {

/**
 * The Resource Primarch extends Attributes by having a min and max value.
 **/
class Resource: public Attribute
{
protected:
    /**
     * Lowest allowable value for the Resource.
     **/
    float minimum;
    
    /**
     * Highest possible value for the Resource.
     **/
    float maximum;

public:
	
	/**
	 * Creates a new Resource.
	 * \param name Name of the resource. Used for all identification purposes in
	 * the managed GameState.
	 * \param min Minimum value.
	 * \param max Maximum value.
	 * \param init Initial value.
	 **/
	Resource(std::string name, float min, float max, float init);

	/**
	 * Creates a new Resource. Sets initial value to the maxiumum value.
	 * \param name Name of the resource. Used for all identification purposes in
	 * the managed GameState.
	 * \param min Minimum value.
	 * \param max Maximum value.
	 **/
	Resource(std::string name, float min, float max);

    /**
     * Destructor.
     * \todo Implement?
     **/
	virtual ~Resource();

    /**
     * Creates an exact clone of the Resource in its current state (i.e.
     * current value intact).
     **/
	virtual Primarch *clone(bool with_id);
	
	/**
	 * Resets the Resource to its initial value.
	 **/
	virtual void reset();
	
	/**
	 * Modifies the Resource by an amount. Will not go beyond minimum or
     * maximum values.
	 * \param amount The amount to change the Resource's value by.
	 **/
	virtual void modify(float amount);
	
	/**
	 * Decreases the Resource's value by a set amount. Will not go below
     * minimum.
	 * \param amount The amount to remove from the Resource.
	 **/
	void decrease(float amount);
	
	/**
	 * Increases the Resource's value by a set amount. Will not go above
     * minimum.
	 * \param amount The amount to add to the Resource.
	 **/
	void increase(float amount);
	
	/**
	 * Changes the minimum value of the Resource.
	 * \param value The new value.
	 **/ 
	void modify_min(float value);

	/**
	 * Changes the maximum value of the Resource.
	 * \param value The new value.
	 **/
	void modify_max(float value);
	
	/**
	 * Prints the Resource's current status to stdout.
	 **/
	void pretty_print();
private:

    /**
     * Initiates the object.
     **/
	void _init(float min, float max);
};

} /* namespace engine */
#endif /* RESOURCE_H_ */
