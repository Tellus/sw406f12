/*
 * PhysicalDamageEffect.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include <string>
#include <iostream>
#include "Effect.h"
#include "Character.h"

namespace testbattle
{

class SexyEffect : public engine::Effect
{
public:
    SexyEffect();
	SexyEffect(engine::RGR_Enum s, engine::RGR_Enum t);

    void execute(engine::Primarch* s, engine::Primarch* t);
	Primarch* clone(bool with_id = false);
};

}
