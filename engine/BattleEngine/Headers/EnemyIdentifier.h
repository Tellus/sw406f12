/*
 * EnemyIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"

namespace engine
{

class EnemyIdentifier : public RGRIdentifier
{
    Character *identify(GameState *from);
    EnemyIdentifier();
};

}
