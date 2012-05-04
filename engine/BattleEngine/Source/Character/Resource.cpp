/*
 * Resource.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Resource.h"

namespace engine
{

Resource::Resource(float min, float max, float init) :
    Attribute(initial)
{
	this->_init(min, max);

	this->initial = this->current = init;
}

Resource::Resource(float min, float max) :
	Attribute(max)
{
	this->_init(min, max);
}

void Resource::_init(float min, float max)
{
    this->modify_min(min);
    this->modify_max(max);
    this->initial = this->current = max;
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

void Resource::decrease(float amount)
{
	std::cout << this->name << ": " << this->current << "-" << amount << " = " << (this->current-amount) << ". ";
	this->current = std::max(this->minimum, this->current-amount);
	std::cout << " Ended up as " << this->current << '\n';
}

void Resource::increase(float amount)
{
	std::cout << this->name << ": " << this->current << "+" << amount << " = " << (this->current+amount) << ".\n";
	this->current = std::max(this->maximum, this->current+amount);
}

void Resource::modify(float amount)
{
	throw "Not supported!";
/*	this->current = std::max(this->
	this->maximum = std::max(this->minimum, this->minimum + amount);
	std::cout << this->name << ": " << */
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
