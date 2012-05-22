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
 * Healing effect.
 * \todo What's a proper healing calculation to you guys?
 **/
class HealEffect : public engine::Effect
{
public:
    /**
     * Creates and initialises without source/target.
     **/
	HealEffect();
	
    /**
     * Creates and initialises.
     * \param s Source of the heal.
     * \param t Target of the heal.
     **/
    HealEffect(engine::RGR_Enum s, engine::RGR_Enum t);
    
    /**
     * Creates and initialises.
     * \param s Source of the heal.
     * \param t Target of the heal.
     * \param amount Modifier to the base amount healed.
     **/
    HealEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount);
};

}
