/*
 * BehaviourRatio.cpp
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#include "BehaviourRatio.h"

namespace engine {

BehaviourRatio::BehaviourRatio(RGR_Enum target, std::string name, float ratio)
{
	// TODO Auto-generated constructor stub
	this->target = target;
	this->name = name;
	this->ratio = ratio;
}

Primarch* BehaviourRatio::get_target(GameState* from)
{
	return from->get_rgr(this->target);
}

} /* namespace engine */
