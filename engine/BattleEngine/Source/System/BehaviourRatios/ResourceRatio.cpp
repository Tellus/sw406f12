/*
 * ResourceRatio.cpp
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#include "BehaviourRatios/ResourceRatio.h"

namespace engine {

ResourceRatio::ResourceRatio(RGR_Enum target, std::string name, float ratio)
	: BehaviourRatio(target, name, ratio)
{}

float ResourceRatio::calculate(GameState* from)
{
	Character* ctar = dynamic_cast<Character*>(this->get_target(from));

	return (ctar->get_resource(this->name)->get_current()) * this->ratio;
}

BehaviourRatio* ResourceRatio::clone()
{
	return new ResourceRatio(this->target, this->name, this->ratio);
}

} /* namespace engine */
