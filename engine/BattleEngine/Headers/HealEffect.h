/*
 * PhysicalDamageEffect.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include "Effect.h"
#include "Character.h"

namespace testbattle {

/**
 * Example effect.
 **/
class HealEffect : public engine::Effect
{
public:
    HealEffect();
    HealEffect(engine::Primarch *s, engine::Primarch *t);

    engine::Character *source_char, *target_char;

    Effect *clone(engine::Primarch *s, engine::Primarch *t);
    
    void execute();
};

}
