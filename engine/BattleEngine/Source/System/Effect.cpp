/*
 * Effect.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Effect.h"
#include <iostream>

namespace engine {

Effect::Effect()
{
	// Stub
}

Effect::~Effect()
{
	// TODO Auto-generated destructor stub
}

Effect::Effect(RGR_Enum s, RGR_Enum t, std::string member, float amount)
{
    this->target_rgr = s;
    this->source_rgr = t;
	this->member = member;
	this->amount = amount;
}

void Effect::pretty_print()
{
    std::cout << "Effect: '" << this->name << "' (" << this->id << ")\n";
}

float Effect::get_value()
{
	return this->amount;
}

} /* namespace engine */
