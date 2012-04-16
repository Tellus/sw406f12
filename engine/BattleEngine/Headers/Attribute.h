/*
 * Attribute.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>

namespace engine {

class Attribute {
protected:
	float current, initial;

public:
	/* Modifies current on Attribute, modifies maximum on Resource */
	virtual void modify(int amount);

	Attribute(int value);
	Attribute(Attribute *copy);
	virtual ~Attribute();

    Attribute(float start);

	std::string pretty_name;

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
};

} /* namespace engine */
#endif /* ATTRIBUTE_H_ */
