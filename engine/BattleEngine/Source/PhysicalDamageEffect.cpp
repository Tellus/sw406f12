/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect(engine::Primarch *s, engine::Primarch *t)
    : engine::Effect(s, t) {}

PhysicalDamageEffect::PhysicalDamageEffect() : engine::Effect() {}

void PhysicalDamageEffect::execute()
{
    // Cast target to Character.<
    this->target_char = (engine::Character*)this->target;
    this->source_char = (engine::Character*)this->source;

    this->target_char->get_resource("Health")->deplete(20);
}

};
