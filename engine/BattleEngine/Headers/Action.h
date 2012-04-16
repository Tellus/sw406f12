/*
 * Action.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "Effect.h"

namespace engine {

class Action {
public:
	virtual ~Action();
	
	/**
	 * Creates a new Action object based on two character objects (source and
	 * target) and an ability.
	 * \param source The character to use this ability.
	 * \param abil The ability to use.
	 * \param target The target to use the ability ON.
	 **/
	Action(Character* source, Ability* abil, Character* target);

	/**
	 * Creates a new Action object based on two character objects (source and
	 * target) and an ability.
	 * \param source The character to use this ability.
	 * \param abil The ability to use.
	 * \param target The RGR to use the ability ON.
	 **/
	Action(Character* source, Ability* abil, RGR_Enum target);
	
protected:
    Character *source_char, *target_char;
    RGR_Enum *target;
    Ability *ability;
};

} /* namespace engine */
#endif /* ACTION_H_ */
