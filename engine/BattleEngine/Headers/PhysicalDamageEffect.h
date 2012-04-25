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
class PhysicalDamageEffect : public engine::Effect
{
public:
    PhysicalDamageEffect();
    PhysicalDamageEffect(engine::Primarch *s, engine::Primarch *t);

    engine::Character *target_char, *source_char;

    Effect *clone(engine::Primarch *s, engine::Primarch *t);
    void execute();
};

}
