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
    HealEffect(engine::RGR_Enum s, engine::RGR_Enum t);
    
    void execute(Primarch* s, Primarch* t);

	Primarch* clone(bool with_id = false);
};

}
