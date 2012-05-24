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
    /**
     * Creates and initialises a (useless) ActionDefinition.
     **/
    ActionDefinition();
    
    /**
     * Creates and initialises a new ActionDefinition.
     * \param src Source of the action. Typically OWNER or SELF.
     * \param trg Target of the action.
     * \param abil Ability to use on the target.
     **/
    ActionDefinition(RGR_Enum src, RGR_Enum trg, Ability* abil);
    
    /**
     * The target of the action. This target will be used as target for the
     * Ability and it is assumed that it is valid.
     **/
    RGR_Enum target;
    
    /**
     * Source of the action. Typically OWNER or SELF, but in the interest of
     * items in future works, it is left to be coded.
     **/
    RGR_Enum source;
    
    /**
     * The Ability to use on the target.
     **/
    Ability* ability;
};

}
#endif // ACTION_DEFINITION_H_
