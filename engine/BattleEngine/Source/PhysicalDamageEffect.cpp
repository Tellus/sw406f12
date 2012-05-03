/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t)
    : engine::Effect(s, t) {}

PhysicalDamageEffect::PhysicalDamageEffect() : engine::Effect() {}

void PhysicalDamageEffect::execute(Primarch* s, Primarch* t)
{
	engine::Character *tchar = dynamic_cast<engine::Character*>(t);

    tchar->get_resource("Health")->deplete(20);
}

engine::Primarch* PhysicalDamageEffect::clone(bool with_id)
{
	engine::Effect *to_ret = new PhysicalDamageEffect(*this);
	return to_ret;
}

};
