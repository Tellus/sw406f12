/*
 * AttackAbility.cpp
 *
 *  Created on: 25/04/2012
 *      Author: Johannes
 */

#include "AttackAbility.h"

namespace testbattle
{

AttackAbility::AttackAbility() :
    Ability("Attack", 0, 0)
{
    this->effects.push_back(new PhysicalDamageEffect());
    this->add_rgr(engine::RGR_Enum::ENEMY);
}

}
