/*
 * WinCondition.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#pragma once

#include <memory>

#include "GameState.h"

namespace engine
{

class WinCondition
{
public:
	WinCondition();
	virtual ~WinCondition();

	/**
	 * Returns true if the win condition has been met. This is what subclasses
	 * should override and implement on their own.
	 */
	virtual bool is_met(GameState* check) = 0;
};

}