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

class Resource:public engine::Attribute
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
	/* At maximum = -1, set it to value */
	Resource(std::string name, float min, float max, float init);
	Resource(std::string name, float min, float max);
	Resource(float min, float max, float init);
	Resource(float min, float max);
	virtual ~Resource();

	virtual Primarch *clone(bool with_id);
	
	virtual void reset();
	virtual void modify(float amount);
	void decrease(float amount);
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
	
	void pretty_print();
private:
	void _init(float min, float max);
};

} /* namespace engine */
#endif /* RESOURCE_H_ */
