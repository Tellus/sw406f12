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

class Attribute : public Primarch
{
protected:
	float current, initial;

public:
	Attribute(float start = 0);
	// Attribute(int initial = 0);
	Attribute(std::string name, float initial = 0);
	// Attribute(std::string name, int initial = 0);
	virtual ~Attribute();

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
	void virtual decrease(float amonut);
	
	/**
	 * Resets the current value to the initial value.
	 **/
	virtual void reset();
	
	/**
	 * Makes a relative change to the current value.
	 * \param amount Amount to change the current value by.
	 **/
	void virtual change(float amount);
	
	float get_current();
	
	void pretty_print();
	
	virtual float get_value();
private:
    /**
     * Sets the initial values.
     **/
    void set_initial(float start);
};

} /* namespace engine */
#endif /* ATTRIBUTE_H_ */
