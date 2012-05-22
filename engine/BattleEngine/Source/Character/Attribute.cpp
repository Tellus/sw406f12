/*
 * Attribute.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Attribute.h"

namespace engine
{

Attribute::Attribute(std::string name, float initial) :
	Primarch(name)
{
	this->name = name;
	this->initial = initial;
}

Attribute::~Attribute()
{
	// Nothing to clean...
}

Primarch* Attribute::clone(bool with_id)
{
	Attribute *ret = new Attribute(this->name, this->initial);
	ret->current = this->current;
	ret->initial = this->initial;
	
	return ret;
}

void Attribute::modify(float amount)
{
	this->current += amount;
}

void Attribute::increase(float amount)
{
    this->current += amount;
}

void Attribute::decrease(float amount)
{
    this->current -= amount;
}

void Attribute::change(float amount)
{
    if (amount < 0)
        this->decrease(amount);
    else if (amount > 0)
        this->increase(amount);
    else return;
}

void Attribute::reset()
{
    this->current = this->initial;
}

float Attribute::get_current()
{
	return this->current;
}

float Attribute::get_value()
{
	return this->get_current();
}

void Attribute::pretty_print()
{
    std::cout << "Attribute: " << this->name << " (" << this->id << ")\n";
}

} /* namespace engine */
