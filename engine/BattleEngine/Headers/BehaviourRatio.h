/*
 * ResourceRatio.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#ifndef BEHAVIOUR_RATIO_H_
#define BEHAVIOUR_RATIO_H_

#include "RGR_Enum.h"
#include <string>
#include "GameState.h"

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
class BehaviourRatio
{
public:
	BehaviourRatio(RGR_Enum target, std::string name, float ratio);
	
	std::string name;
	float ratio;
	RGR_Enum target;

	/**
	 * Helper function. Retrieves the Primarch associated with the
	 * BehaviourRatio's target RGR.
	 **/
	virtual Primarch* get_target(GameState* from);

	/**
	 * Calculates.
	 **/
	virtual float calculate(GameState* from);

	virtual BehaviourRatio* clone();
};

} /* namespace engine */

#endif
