/*
 * RGRIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

// #include "GameState.h"

#include "Character.h"

namespace engine
{

// Forward declaration - ew.
class GameState;

class RGRIdentifier
{
public:
	RGRIdentifier();
	RGRIdentifier(int rgr_id);
	virtual ~RGRIdentifier();
	
	/**
     * RGR_Enum value that this RGRIdentifier is able to identify.
     **/
    RGR_Enum rgr;
    
    /**
     * Identifies a character from a given GameState. This method is overridden
     * in RGRIdentifier subclasses to exhibit specialised behaviour.
     * \param from The GameState to search through.
     * \return Pointer to the Character object identified, or NULL if none were
     * found.
     **/
    virtual Character *identify(GameState *from) = 0;
    
private:
    void _init();
};

}
