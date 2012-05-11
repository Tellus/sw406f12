/*
 * EnemyIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#ifndef ENEMY_IDENTIFIER_H_
#define ENEMY_IDENTIFIER_H_

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"
#include "PrettyPrinter.h"

namespace engine
{

class EnemyIdentifier : public RGRIdentifier
{
public:
    Character *identify(GameState *from);
    EnemyIdentifier();
};

}

#endif
