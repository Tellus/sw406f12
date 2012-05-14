/*
 * EventListener.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef EVENTLISTENER_H_
#define EVENTLISTENER_H_

#include "RGR_Enum.h"
#include "EventCondition.h"
#include "ActionDefinition.h"

namespace engine {

/**
 * A glorified std::pair. Contains and handles the two parts of an event,
 * the conditional and the reaction.
 **/
class EventListener
{
public:
	EventListener();
	EventListener(EventCondition* ec, ActionDefinition* ac);
	virtual ~EventListener();
	
	EventCondition* condition;
	ActionDefinition* action;
	
	/**
	 * Sets the condition for the event's execution. Roughly equivalent to
	 * this->condition = Condition(target, member, comp, value);
	 * \param target The target to observe.
	 * \param member The member of the target to measure.
	 * \param comp The comparison method.
	 * \param value The value to compare against.
	 **/
	void set_condition(RGR_Enum target, std::string member, COMPARISON_ENUM comp, float value);
	
	/**
	 * Set the action of this EventListener.
	 * \param abil The ability to invoke if the event is raised.
	 * \param target The target of the ability. Should be one of the valid
     * targets in the ability, otherwise an exception will be thrown later.
	 **/
	void set_action(Ability* abil, RGR_Enum target);
};

} /* namespace engine */
#endif /* EVENTLISTENER_H_ */
