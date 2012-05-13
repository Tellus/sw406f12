/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect()
{
	this->name = "Physical Effect";
	this->amount = -20;
	this->member = "Health";
	this->target_rgr = engine::TARGET;
	this->source_rgr = engine::OWNER;
}

};
