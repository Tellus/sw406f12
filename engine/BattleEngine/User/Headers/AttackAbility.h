/*
 * AttackAbility.h
 *
 *  Created on: 25/04/2012
 *      Author: Johannes
 */

#pragma once

#include "Ability.h"
#include "PhysicalDamageEffect.h"

namespace testbattle
{

/**
 * Basic attacking ability. Does PhysicalDamage.
 **/
class AttackAbility : public engine::Ability
{
public:
    /**
     * Initialises.
     **/
    AttackAbility();
};

};
