/*
 * Resource.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../Headers/Resource.h"

using namespace std;

double Resource::percent()
{
	return this->current / this->maximum;
}

void Resource::init(double value)
{
	this->maximum = value;
	Attribute::init(value);
}

void Resource::deplete(double amount)
{
	this->current = max(0.0, this->current - amount);
}

Resource::Resource(string name) : Attribute(name)
{
}

Resource::Resource(string name, double value) : Attribute(name)
{
	this->init(value);
}

Resource::Resource(Resource *copy) : Attribute(copy->name)
{
	this->init(copy->initial);
}

Resource::~Resource() {
	// TODO Auto-generated destructor stub
}
