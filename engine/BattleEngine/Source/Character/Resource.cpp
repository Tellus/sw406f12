/*
 * Resource.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Resource.h"

namespace engine {

Resource::Resource()
{
	// TODO Auto-generated constructor stub
}

Resource::Resource(float min, float max, float initial) : Attribute(initial)
{
    this->modify_min(min);
    this->modify_max(max);
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
