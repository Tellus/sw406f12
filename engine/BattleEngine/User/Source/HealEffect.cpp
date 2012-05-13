/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "HealEffect.h"

namespace testbattle{


HealEffect::HealEffect()
{
	this->name = "Heal Effect";
	this->amount = 10;
	this->member = "Health";
	this->target_rgr = engine::TARGET;
	this->source_rgr = engine::OWNER;
}

};
