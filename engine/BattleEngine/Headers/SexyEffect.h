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
    engine::Character *source_char, *target_char;

    SexyEffect(engine::Primarch *s, engine::Primarch *t);
    SexyEffect();
    void execute();
};

}
