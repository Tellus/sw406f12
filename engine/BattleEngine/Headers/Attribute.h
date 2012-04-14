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
	float current;

public:
	Attribute();
	virtual ~Attribute();
<<<<<<< HEAD

    Attribute(float start);

	float initial;
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
	void reset();
	
	/**
	 * Makes a relative change to the current value.
	 * \param amount Amount to change the current value by.
	 **/
	void virtual change(float amount);
=======
>>>>>>> parent of 8a31347... Created Attributes and resources
};

} /* namespace engine */
#endif /* ATTRIBUTE_H_ */
