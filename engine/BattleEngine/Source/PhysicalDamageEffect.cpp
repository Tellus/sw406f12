/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

void PhysicalDamage::execute()
{
    // Cast target to Character.
    this->target_char = (Character*)this->target;
    this->source_char = (Character*)this->source;

    // SHOULD be: WeaponDMG + Strength/2 + 1
    // Damage reduction unknown right now.
    this->target->health -= 20;
	// Should have: (this->source->attributes["Strength"]->current / 2) + 1;
}
