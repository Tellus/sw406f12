/*
 * Attribute.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include "Primarch.h"
#include <string>

namespace engine {

/** 
 * The Attribute Primarch is Strength, Intelligence and the like. It's quite
 * simply put a float with a name and a reset button.
 **/
class Attribute : public Primarch
{
protected:
    /**
     * Current value of the Attribute.
     **/
	float current;
	
	/**
	 * Initial value of the Attribute.
	 **/
	float initial;

public:
	/**
	 * Creates a new Attribute.
	 * \param name Primarch Name of the Attribute.
	 * \param initial Starting value of the Attribute.
	 **/
	Attribute(std::string name, float initial = 0);
	
	/**
	 *
	 **/
	virtual ~Attribute();

    /**
     * Creates an exact copy of the Attribute in its current state.
     * \param with_id If true, the copy will be exact, i.e. the Attribute will
     * be distinguishable from its original only in memory. If false, the 
     * Attribute will be created as a new Attribute with a new Primarch Id.
     **/
	virtual Primarch *clone(bool with_id);
	
	/**
	 * Modifies the current value of the Attribute. Modifies the maximum on
	 * Resources (... *WHAT*?!).
	 */
	virtual void modify(float amount);

	/**
	 * Increase the current value of the attribute... duh.
	 * \param amount The amount to increase by.
	 **/
	void virtual increase(float amount);
	
	/**
	 * Decrease the current value of the attribute.
	 * \param amount Amount to decrease by.
	 **/
	void virtual decrease(float amount);
	
	/**
	 * Resets the current value to the initial value.
	 **/
	virtual void reset();
	
	/**
	 * Makes a relative change to the current value.
	 * \param amount Amount to change the current value by.
	 **/
	void virtual change(float amount);
	
	/**
	 * Retrieves the current value of the Attribute.
	 * \return The current value.
	 **/
	float get_current();
	
	/**
	 * Outputs the Attribute's data in a human-readable format to stdout.
	 **/
	void pretty_print();
	
	/**
	 * Inherited from Primarch. Proxy for get_current().
	 * \see get_current()
	 **/
	virtual float get_value();
};

} /* namespace engine */
#endif /* ATTRIBUTE_H_ */
