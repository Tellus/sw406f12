/*
 * FullBehaviour.cpp
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#include "FullBehaviour.h"

namespace engine {

FullBehaviour::FullBehaviour()
{
	// TODO Auto-generated constructor stub

}

FullBehaviour::~FullBehaviour()
{
	// TODO Auto-generated destructor stub
}

void FullBehaviour::_init()
{
	this->ratios = std::list<BehaviourRatio*>();
}

float FullBehaviour::get_piggy(GameState* from)
{
    // FullBehaviour runs through each ratio collection and tests them.
	// A piggy is simply them all summed up.
	float pig = 0;
	
	for (std::list<BehaviourRatio*>::iterator iter = this->ratios.begin();
		iter != this->ratios.end();
		iter++)
	{
		pig += (*iter)->calculate(from);
	}

	return pig;
}

void FullBehaviour::add_ratio(BehaviourRatio* add)
{
	this->ratios.push_back(add);
}

void FullBehaviour::remove_ratio(std::string name)
{
	for (std::list<BehaviourRatio*>::iterator iter = this->ratios.begin();
		 iter != this->ratios.end();
		 iter++)
	{
		if ((*iter)->name == name)
		{
			this->ratios.remove((*iter));
			return;
		}
	}
}

Behaviour* FullBehaviour::clone()
{
	FullBehaviour* nb = new FullBehaviour();

	for (std::list<BehaviourRatio*>::iterator iter = this->ratios.begin();
		iter != this->ratios.end();
		iter++)
	{
		nb->add_ratio((*iter)->clone());
	}

	return nb;

}

} /* namespace engine */
