/*
 * HealAbility.cpp
 *
 *  Created on: 25/04/2012
 *      Author: Johannes
 */

#include "HealAbility.h"

namespace testbattle
{

HealAbility::HealAbility() :
    Ability("Heal", 0, 25)
{
    HealEffect *eff = new HealEffect();
    this->effects.push_back(eff);
    this->add_rgr(engine::OWNER);
}


}
