/*
 * Action.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "Primarch.h"
#include "Ability.h"
#include "RGR_List.h"

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
	Action(Primarch* source, Ability* abil, Primarch* target);

	/**
	 * Creates a new Action object based on two character objects (source and
	 * target) and an ability.
	 * \param source The character to use this ability.
	 * \param abil The ability to use.
	 * \param target The RGR to use the ability ON.
	 **/
	Action(Primarch* source, Ability* abil, RGR_Enum target);
	
	/**
	 * Generates and applies the effects to the given target
	 */
	void execute();

protected:
    Primarch *source, *target;
    RGR_Enum *target_rgr;
    Ability *ability;


    /**
     * Called by execute, to generate a collections of effects from effectDefinitions
     */
    void generate_effects();
};

} /* namespace engine */
#endif /* ACTION_H_ */
