/*
 * WinCondition.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#ifndef WIN_CONDITION_H_
#define WIN_CONDITION_H_

#include <memory>

#include "GameState.h"

namespace engine
{

/**
 * Abstract winning condition. Inherit and implement the is_met method to add a
 * new win condition to an Engine instance.
 **/
class WinCondition
{
public:
	/**
	 * Returns true if the win condition has been met. This is what subclasses
	 * should override and implement on their own.
	 */
	virtual bool is_met(GameState* check) = 0;
};

}

#endif
