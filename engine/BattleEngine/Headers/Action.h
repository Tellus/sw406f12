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
#include "GameState.h"
#include "Exceptions/NullParameterException.h"

#include <typeinfo>

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
	Action(RGR_Enum source, RGR_Enum target, Ability* abil);
	
	/**
	 * Creates a new cloned GameState and runs the effects on it.
	 * \param thru The GameState to run the execution through.
	 * \return A (new) modified GameState.
	 */
	GameState* execute(GameState *thru);

    // Primarch *source, *target;
	/**
	 * RGR references to the targets of this particular action. Typically, this
	 * will distill the list of targets of an Ability down to the few necessary.
	 */
	RGR_Enum source, target;

    Ability *ability;

protected:
    /**
     * Called by execute, to generate a collections of effects from effectDefinitions
     */
    std::vector<Effect*> *generate_effects();
};

} /* namespace engine */
#endif /* ACTION_H_ */
