d ../*
 * OwnerIdentifier.h
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#ifndef SELF_IDENTIFIER_H_
#define SELF_IDENTIFIER_H_

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"

namespace engine
{

/**
 * RGRIdentifier for the SELF RGR_Enum. Identical to OwnerIdentifier.
 **/
class SelfIdentifier
{
public:
    /**
     * Finds the SELF Character in a GameState.
     * \param from The GameState to look through.
     * \return from->current_character - always.
     **/
    Character *identify(GameState *from);
    
    /**
     * Creates and initialises a new SelfIdentifier.
     **/
    SelfIdentifier();
};

}

#endif
