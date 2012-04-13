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

Attribute::Attribute(Attribute *copy)
{
	this->current = copy->current;
	this->initial = copy->initial;
}

Attribute::~Attribute()
{
	// Nothing to clean...
}

} /* namespace engine */
