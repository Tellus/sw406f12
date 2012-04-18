/*
 * Effect.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Effect.h"

namespace engine {

Effect::Effect()
{
	// TODO Auto-generated constructor stub

}

Effect::~Effect()
{
	// TODO Auto-generated destructor stub
}

/** Example: PhysicalDamage **/
void PhysicalDamage::execute()
{
    // SHOULD be: WeaponDMG + Strength/2 + 1
    // Damage reduction unknown right now.
    this->target->health -= 20;
	// Should have: (this->source->attributes["Strength"]->current / 2) + 1;
}

} /* namespace engine */
