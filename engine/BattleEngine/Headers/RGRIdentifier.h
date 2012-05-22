/*
 * RGRIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#ifndef RGR_IDENTIFIER_H_
#define RGR_IDENTIFIER_H_

#include "Character.h"

namespace engine
{

// Forward declaration - ew.
class GameState;

/**
 * Base class for any RGR_Enum identifier for GameStates. Subclasses are found
 * in the RGRIdentifier subdirectory of Source/System.
 **/
class RGRIdentifier
{
public:
    /**
     * Creates and initialises a new RGRIdentifier. Currently, this is simply
     * a question of denoting which RGR_Enum that the identifier works with.
     **/
	RGRIdentifier();

    /**
     * Creates and initialises a new RGRIdentifier. Currently, this is simply
     * a question of denoting which RGR_Enum that the identifier works with.
     * \param rgr_id RGR_Enum that this identifier should work with.
     **/	
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
    /**
     * Initialisation.
     **/
    void _init();
};

}

#endif
