/*
 * EnemyIdentifier_Unsafe.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"
#include "PrettyPrinter.h"

namespace engine
{

class EnemyIdentifier_Unsafe : public RGRIdentifier
{
public:
    Character *identify(GameState *from);
    EnemyIdentifier_Unsafe();
};

}
