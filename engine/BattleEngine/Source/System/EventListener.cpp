/*
 * EventListener.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "EventListener.h"

namespace engine {

EventListener::EventListener() {
	// TODO Auto-generated constructor stub

}

EventListener::~EventListener() {
	// TODO Auto-generated destructor stub
}

void EventListener::set_condition(RGR_Enum target, std::string member, COMPARISON_ENUM comp, float value)
{
	this->condition = EventCondition(target, member, comp, value);
}

void EventListener::set_action(Ability* abil, RGR_Enum target)
{
    this->action = ActionDefinition(OWNER, target, abil);
}

} /* namespace engine */
