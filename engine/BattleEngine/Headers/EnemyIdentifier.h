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

/**
 * RGRIdentifier responsible for resolving the RGR_Enum ENEMY.
 **/
class EnemyIdentifier : public RGRIdentifier
{
public:
    /**
     * Identifies an ENEMY Character in a GameState.
     * \param from The GameState to analyse.
     * \return The Character found, or NULL.
     **/
    Character *identify(GameState *from);
    
    /** 
     * Creates and initialises an EnemyIdentifier.
     **/
    EnemyIdentifier();
};

}

#endif
