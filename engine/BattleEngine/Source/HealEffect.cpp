/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "HealEffect.h"

namespace testbattle{

HealEffect::HealEffect() : engine::Effect() {}

HealEffect::HealEffect(engine::Primarch *s, engine::Primarch *t) :
    engine::Effect(s, t)
{
    // Empty, see intializer.
}

void HealEffect::execute()
{
    // Cast target to Character.
    this->target_char = (engine::Character*)this->target;
    this->source_char = (engine::Character*)this->source;

    // Heals for 40 health.
    this->target_char->get_resource("Health")->regain(40);
}

engine::Effect *HealEffect::clone(engine::Primarch *source, engine::Primarch *target)
{
    return new HealEffect(source, target);
}
};
