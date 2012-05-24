/*
 * PhysicalDamageEffect.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include "Effect.h"
#include "Attribute.h"
#include "Character.h"

namespace testbattle {

/**
 * PhysicalDamageEffect makes use of the source Character's strengt and attack
 * power as well as the target Character's physical (regular) defense stats.
 **/
class PhysicalDamageEffect : public engine::Effect
{
public:
    /**
     * Creates and initialises without source/target.
     **/
    PhysicalDamageEffect();
    
    /**
     * Creates and initialises.
     * \param s Source of the damage.
     * \param t Target of the damage.
     **/
	PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t);
	
    /**
     * Creates and initialises.
     * \param s Source of the damage.
     * \param t Target of the damage.
     * \param amount Modifier to the base amount damaged.
     **/
	PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount);

    /**
     * Override of base execution model. Since we have some custom calculations
     * for physical damage, we perform them here in our own implementation.
     * \param s Source of the damage (will be used for strength/ap).
     * \param t Target of the damage (will be used for defense).
     **/
    void execute(Primarch* s, Primarch* t);
    
    virtual Primarch* clone(bool with_id = true);
};

}
