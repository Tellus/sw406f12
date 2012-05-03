/*
 * Resource.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Resource.h"

namespace engine
{


Resource::Resource(int value, int maximum, int minimum) : Attribute(value)
{
	if (maximum == -1)
		maximum = value;

	this->initial = static_cast<float>(maximum);
	this->maximum = static_cast<float>(maximum);
	this->minimum = static_cast<float>(minimum);
}

Resource::Resource(float min, float max, float initial) :
    Attribute(initial)
{
    this->modify_min(min);
    this->modify_max(max);
    this->initial = initial;
    this->current = max;
}

Resource::~Resource()
{
	// TODO Auto-generated destructor stub
}

Primarch* Resource::clone(bool with_id)
{
	Resource* to_ret = new Resource(this->minimum, this->maximum, this->initial);
	return to_ret;
}

void Resource::deplete(int amount)
{
	this->current = std::max(this->minimum, this->current - amount);
}

void Resource::regain(int amount)
{
	this->current = std::min(this->maximum, this->current + amount);
}

void Resource::modify(int amount)
{
	this->maximum = std::max(this->minimum, this->minimum + amount);
}

void Resource::reset()
{
	this->maximum = initial;
}

void Resource::modify_min(float value)
{
    this->minimum = value;
}

void Resource::modify_max(float value)
{
    this->maximum = value;
}

void Resource::pretty_print()
{
    std::cout << "Resource: " << this->name << " (" << this->id << ") " << this->minimum << '/' << this->current << '/' << this->maximum << '\n';
}

} /* namespace engine */
