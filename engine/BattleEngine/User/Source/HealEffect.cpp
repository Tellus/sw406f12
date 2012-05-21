/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "HealEffect.h"

namespace testbattle{

HealEffect::~HealEffect()
{
// Stub
}

HealEffect::HealEffect(engine::RGR_Enum s, engine::RGR_Enum t) :
    engine::Effect(s, t, "health", 10) {}

HealEffect::HealEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount) :
    engine::Effect(s, t, "health", amount) {}

HealEffect::HealEffect() :
    engine::Effect(engine::OWNER, engine::TARGET, "health", 10) {}
}
