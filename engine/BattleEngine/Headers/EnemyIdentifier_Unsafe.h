/*
 * EnemyIdentifier_Unsafe.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#ifndef ENEMY_IDENTIFIER_UNSAFE_H_
#define ENEMY_IDENTIFIER_UNSAFE_H_

#include <list>

#include "GameState.h"
#include "Character.h"
#include "RGRIdentifier.h"
#include "PrettyPrinter.h"

namespace engine
{

/** 
 * A haphazar version of EnemyIdentifier that will also target the current
 * Character. Should only be used for some debugging scenarios.
 **/
class EnemyIdentifier_Unsafe : public RGRIdentifier
{
public:
    /**
     * Identifies the first valid ENEMY Character in a state, or the Character
     * itself.
     * \param from The GameState to analyse.
     * \return The first found ENEMY or the current Character (OWNER).
     **/
    Character *identify(GameState *from);
    
    /** 
     * Creates and initialises a new EnemyIdentifier.
     * SHOULD NOT BE USED SIMULTANEOUSLY WITH EnemyIdentifier!
     **/
    EnemyIdentifier_Unsafe();
};

}

#endif
