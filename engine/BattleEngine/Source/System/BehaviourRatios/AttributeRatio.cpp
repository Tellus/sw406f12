/*
 * AttributeRatio.cpp
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#include "BehaviourRatios/AttributeRatio.h"

namespace engine {

AttributeRatio::AttributeRatio(RGR_Enum target, std::string name, float ratio)
	: BehaviourRatio(target, name, ratio)
{}

float AttributeRatio::calculate(GameState* from)
{
	Character* ctar = dynamic_cast<Character*>(this->get_target(from));

	return (ctar->get_attribute(this->name)->get_current()) * this->ratio;
}

BehaviourRatio* AttributeRatio::clone()
{
	return new AttributeRatio(this->target, this->name, this->ratio);
}

} /* namespace engine */
