/*
 * RGRIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

#include "GameState.h"
#include "Character.h"

namespace engine
{

class RGRIdentifier
{
public:
    int rgr;
    virtual Character *identify(GameState *from) = 0;
	RGRIdentifier();
	virtual ~RGRIdentifier();
};

}
