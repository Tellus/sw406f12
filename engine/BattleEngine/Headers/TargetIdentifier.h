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

class TargetIdentifier : public RGRIdentifier
{
public:
    Character *identify(GameState *from);
    TargetIdentifier();
};

}

#endif
