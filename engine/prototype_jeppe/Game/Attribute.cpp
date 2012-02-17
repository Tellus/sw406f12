/*
 * Attribute.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "Headers/Attribute.h"

void Attribute::init(double value)
{
	this->initial = value;
	this->current = value;
}

Attribute::Attribute(string name) {
	this->name = name;
	// TODO Auto-generated constructor stub
}

Attribute::Attribute(string name, double value)
{
	this->name = name;
	this->init(value);
}

Attribute::Attribute(Attribute *copy)
{
	this->name = copy->name;
	this->init(copy->initial);
}

Attribute::~Attribute() {
	// TODO Auto-generated destructor stub
}

