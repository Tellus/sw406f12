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

class OwnerIdentifier : public RGRIdentifier
{
public:
    Character *identify(GameState *from);
    OwnerIdentifier();
};

}

#endif
