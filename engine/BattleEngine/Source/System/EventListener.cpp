/*
 * EventListener.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "EventListener.h"

namespace engine {

EventListener::EventListener() {
    this->condition = NULL;
    this->action = NULL;
}

EventListener::EventListener(EventCondition* ec, ActionDefinition* ac)
{
    this->condition = ec;
    this->action = ac;
}

EventListener::~EventListener() {
    delete this->condition;
    delete this->action;
}

void EventListener::set_condition(RGR_Enum target, std::string member, COMPARISON_ENUM comp, float value)
{
	this->condition = new EventCondition(target, member, comp, value);
}

void EventListener::set_action(Ability* abil, RGR_Enum target)
{
    this->action = new ActionDefinition(OWNER, target, abil);
}

} /* namespace engine */
