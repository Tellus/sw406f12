/*
 * Resource.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Attribute.h"

#include <algorithm>

namespace engine {

class Resource:public engine::Attribute {
protected:
    /**
     * Lowest allowable value for the Resource.
     **/
    float minimum;
    
    /**
     * Highest possible value for the Resource.
     **/
    float maximum;

    float initial_minimum;

public:
	/* At maximum = -1, set it to value */
	Resource(int value, int maximum = -1, int minimum = 0);
	Resource(Resource *copy);
	virtual ~Resource();

	void deplete(int amount);
	void regain(int amount);
	void modify_minimum(int amount);
	virtual void reset();
	virtual void modify(int amount);
	
	Resource(float min, float max, float initial);
	
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
};

} /* namespace engine */
#endif /* RESOURCE_H_ */
