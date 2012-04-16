/*
 * Attribute.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Attribute.h"

namespace engine
{

void Attribute::modify(int amount)
{
	this->current += amount;
}

void Attribute::reset()
{
	this->current = this->initial;
}

Attribute::Attribute(int value)
{
	this->current = value;
	this->initial = value;
}

Attribute::Attribute()
{
	// TODO Auto-generated constructor stub
}

Attribute::Attribute(Attribute *copy)
{
	this->current = copy->current;
	this->initial = copy->initial;
}

Attribute::~Attribute()
{
	// Nothing to clean...
}

Attribute::Attribute(float start)
{
    this->current = this->initial = start;
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

} /* namespace engine */
