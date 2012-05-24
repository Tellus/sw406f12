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
    this->add_effect(new PhysicalDamageEffect());
    this->add_rgr(engine::ENEMY);
}

}
