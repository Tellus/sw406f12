/*
 * OwnerIdentifier.h
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#ifndef OWNER_IDENTIFIER_H_
#define OWNER_IDENTIFIER_H_

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"

namespace engine
{

/**
 * RGRIdentifier responsible for resolving the OWNER RGR_Enum. This is most
 * typically current_character in a GameState.
 **/
class OwnerIdentifier : public RGRIdentifier
{
public:
    /**
     * Finds the OWNER Character in a GameState.
     * \param from The GameState to look through.
     * \return from->current_character - always.
     **/
    Character *identify(GameState *from);
    
    /**
     * Creates and initialises a new OwnerIdentifier.
     **/
    OwnerIdentifier();
};

}

#endif
