/*
 * Resource.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "Headers/Resource.h"

void Resource::init(double value)
{
	this->maximum = value;
	Attribute::init(value);
}

Resource::Resource(string name, double value)
{
	this->init(value);
}

Resource::Resource(Resource *copy)
{
	this->init(copy->initial);
}

Resource::Resource() {
	// TODO Auto-generated constructor stub
}

Resource::~Resource() {
	// TODO Auto-generated destructor stub
}
