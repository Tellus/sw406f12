/*
 * Resource.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Resource.h"

namespace engine
{

<<<<<<< HEAD
void Resource::deplete(int amount)
{
	this->current = std::max(this->minimum, this->current - amount);
}

void Resource::regain(int amount)
{
	this->current = std::min(this->maximum, this->current + amount);
}

void Resource::modify_minimum(int amount)
{
	this->minimum = std::min(this->maximum, this->minimum + amount);
}

void Resource::modify(int amount)
{
	this->maximum = std::max(this->minimum, this->minimum + amount);
}

void Resource::reset()
{
	this->maximum = initial;
	this->minimum = initial_minimum;
}

Resource::Resource(int value, int maximum, int minimum) : Attribute(value)
{
	if (maximum == -1)
		maximum = value;

	this->initial = maximum;
	this->maximum = maximum;
	this->initial_minimum = minimum;
	this->minimum = minimum;
}

Resource::Resource(Resource *copy) : Attribute(0)
{
	this->current = copy->current;
	this->initial = copy->initial;
	this->maximum = copy->maximum;
	this->minimum = copy->minimum;
	this->initial_minimum = copy->initial_minimum;
=======
Resource::Resource()
{
	// TODO Auto-generated constructor stub
}

Resource::Resource(float min, float max, float initial) : Attribute(initial)
{
    this->modify_min(min);
    this->modify_max(max);
>>>>>>> d22b1314e2f5406186daab34289994c653fb9e77
}

Resource::~Resource()
{
	// TODO Auto-generated destructor stub
}

void Resource::modify_min(float value)
{
    this->minimum = value;
}

void Resource::modify_max(float value)
{
    this->maximum = value;
}

} /* namespace engine */
