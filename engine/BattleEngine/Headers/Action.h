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
	 * Generates and applies the effects to the given target
	 */
	void execute();

    Primarch *source, *target;
    Ability *ability;

protected:
    /**
     * Called by execute, to generate a collections of effects from effectDefinitions
     */
    std::vector<Effect*> *generate_effects();
};

} /* namespace engine */
#endif /* ACTION_H_ */
