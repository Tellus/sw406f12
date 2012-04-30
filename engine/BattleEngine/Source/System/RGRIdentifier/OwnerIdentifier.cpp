/*
 * OwnerIdentifier.cpp
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#include "OwnerIdentifier.h"

namespace engine
{

OwnerIdentifier::OwnerIdentifier()
{
    this->rgr = OWNER;
}

Character *OwnerIdentifier::identify(GameState *from)
{
    return from->current_char;
}

}
