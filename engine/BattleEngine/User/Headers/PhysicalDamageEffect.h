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
	PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t);
	PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount);

    virtual void execute(engine::Primarch* s, engine::Primarch* t);

	Primarch* clone(bool with_id = false);
};

}
