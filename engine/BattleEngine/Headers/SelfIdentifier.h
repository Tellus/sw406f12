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

class SelfIdentifier : public SelfIdentifier
{
public:
    Character *identify(GameState *from);
    SelfIdentifier();
};

}

#endif
