/*
 * OwnerIdentifier.cpp
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#include "OwnerIdentifier.h"

namespace engine
{

SelfIdentifier::SelfIdentifier()
{
    this->rgr = OWNER;
}

Character *SelfIdentifier::identify(GameState *from)
{
    return from->current_char;
}

}
