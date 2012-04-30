/*
 * OwnerIdentifier.h
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#pragma once

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
