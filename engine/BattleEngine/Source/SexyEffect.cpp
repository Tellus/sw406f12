/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "SexyEffect.h"

namespace testbattle{

SexyEffect::SexyEffect() : engine::Effect() {}

SexyEffect::SexyEffect(engine::Primarch *s, engine::Primarch *t)
{
    this->target = t;
    this->source = s;
}

void SexyEffect::execute()
{
    // Cast target to Character.
    this->target_char = (engine::Character*)this->target;
    this->source_char = (engine::Character*)this->source;

    // Heals for 40 health.
    this->target_char->get_resource("Health")->regain(40);
}
};
