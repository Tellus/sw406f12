/*
 * PhysicalDamageEffect.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include "Effect.h"
#include "Character.h"

namespace engine {

/**
 * Example effect.
 **/
class PhysicalDamageEffect : public Effect
{
public:
    Character *target_char;
    Character *source_char;

    virtual void execute();
};

}