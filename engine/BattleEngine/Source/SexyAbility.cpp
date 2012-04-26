/*
 * SexyAbility.cpp
 *
 *  Created on: 25/04/2012
 *      Author: Johannes
 */

#include "SexyAbility.h"

#include <iostream>

namespace testbattle
{

SexyAbility::SexyAbility() :
    Ability(25,0)
{
    SexyEffect *eff = new SexyEffect();
    this->effects.push_back(eff);
    this->add_rgr(engine::RGR_Enum::ALL);
}

}
