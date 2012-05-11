/*
 * ActionDefinition.h
 *
 *  Created on: 11/05/2012
 *      Author: Johannes
 */

#ifndef ACTION_DEFINITION_H_
#define ACTION_DEFINITION_H_

#include "RGR_Enum.h"
#include "Ability.h"

namespace engine
{

/**
 * Defines a concrete action to be taken. See Action.h for resolving the action
 * in a GameState.
 **/
class ActionDefinition
{
public:
    ActionDefinition();
    ActionDefinition(RGR_Enum src, RGR_Enum trg, Ability* abil);
    
    RGR_Enum target;
    RGR_Enum source;
    Ability* ability;
};

}
#endif // ACTION_DEFINITION_H_
