/*
 * BehaviourRatio.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#pragma once

#include <string>

#include "BehaviourRatio.h"
#include "RGR_Enum.h"
#include "GameState.h"

// I'm too slow to figure an alternative to forward declaration.
namespace engine{
class GameState;
}

namespace engine {

/**
 * The BehaviourRatio class tries to be a generic cure-all for Behaviour
 * calculations. It's basically a triple, but is completely separated from
 * Behaviour itself (meaning that the references to GameState and RGR_Enum
 * should be safe). The prime caveat is that Primarchs don't all have a
 * universal "current" value to calculate from, so we can't just se up
 * a flexible reflective system. We must subclass BehaviourRatio for
 * different Primarchs.
 */
class ResourceRatio : public BehaviourRatio
{
public:
	ResourceRatio(RGR_Enum target, std::string name, float ratio);
	
	/**
	 * Calculates
	 **/
	virtual float calculate(GameState* from);

	BehaviourRatio* clone();
};

} /* namespace engine */
