/*
 * HealAbility.h
 *
 *  Created on: 25/04/2012
 *      Author: Johannes
 */

#pragma once

#include "Ability.h"
#include "HealEffect.h"

namespace testbattle
{

/**
 * Basic healing ability. Uses the HealEffect.
 **/
class HealAbility : public engine::Ability
{
public:
    /**
     * Create and initialise.
     **/
    HealAbility();
};

};
