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
	this->amount = 1; // Otherwise, most derived effects will have a zero-effect
	                  // magnitude.
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

void Effect::modify(float amount)
{
	this->amount = amount;
}

void Effect::execute(Primarch* s, Primarch* t)
{
    std::cout << "WARNING! Base Effect class executed!\n";
	t->get_child(this->member)->modify(this->amount);
}

Primarch* Effect::clone(bool with_id)
{
	// Effect* eff = new Effect(this->source, this->target
	Effect* eff = new Effect(this->source_rgr, this->target_rgr, this->member, this->amount);

	eff->name = this->name;

	if (with_id)
		eff->id = this->id;

	return eff;
}

} /* namespace engine */
