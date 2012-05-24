/*
 * Target.h
 *
 *  Created on: 13/05/2012
 *      Author: Johannes
 */

#ifndef TARGET_IDENTIFIER_H_
#define TARGET_IDENTIFIER_H_

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"

namespace engine
{

/** 
 * RGRIdentifier responsible for resolving the TARGET RGR_Enum.
 **/
class TargetIdentifier : public RGRIdentifier
{
public:
    /**
     * Identifies the target from a GameState. Requires that set_target has
     * been called on the GameState beforehand.
     * \param from The GameState to analyse.
     * \return The found Character or NULL.
     **/
    Character *identify(GameState *from);
    
    /**
     * Creates and initialises a new TargetIdentifier.
     **/
    TargetIdentifier();
};

}

#endif
