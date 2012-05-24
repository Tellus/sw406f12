/*
 * Behaviour.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

// I'm too slow to figure an alternative to forward declaration.
namespace engine{
class GameState;
}

namespace engine {

/**
 * The Behaviour class is the super class of any sort of Behaviour. In its
 * current form it's quite impotent, and you probably came here looking for
 * FullBehaviour instead.
 * \see FullBehaviour
 **/
class Behaviour
{
public:
	/**
	 * Calculates the piggy value depending on the premises given for the
	 * current Behaviour child class.
	 * \param from Pointer to the GameState to get piggy from. We need a
	 * direct way to retrieve game data, and that is through GameState.
	 * It's unfortunate this creates a reference loop via
	 * GameState -> Character -> Behaviour -> GameState.
	 **/
	virtual float get_piggy(GameState* from) = 0;

    /**
     * Clones the Behaviour. Identical to using a copy-constructor (since no
     * data is actually copied right now).
     **/
	virtual Behaviour* clone() = 0;
};

} /* namespace engine */

#endif
