/*
 * ActionDefinition.cpp
 *
 *  Created on: 11/05/2012
 *      Author: Johannes
 */

#include "ActionDefinition.h"

namespace engine
{

ActionDefinition::ActionDefinition()
{
    this->ability = NULL;
}

ActionDefinition::ActionDefinition(RGR_Enum src, RGR_Enum trg, Ability* abil)
{
    this->source = src;
    this->target = trg;
    this->ability = abil;
}

}
