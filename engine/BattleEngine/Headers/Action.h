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

/**
 * The Action class defines an action to be taken. It allows for tracking
 * Character choices as well as storing these choices without having impacted a
 * GameState. They can also affect GameStates.
 * Action distances itself from ActionDefinition in that it has the capability
 * to help resolve RGR_Enums.
 **/
class Action {
public:
    /**
     * \todo Implement.
     **/
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
	 * Creates a new Action from an ActionDefinition.
	 **/
	Action(ActionDefinition to_use);
	
	/**
	 * Creates a new cloned GameState and runs the effects on it.
	 * \param thru The GameState to run the execution through.
	 * \return A (new) modified GameState.
	 */
	GameState* execute(GameState *thru);

    /**
     * Definition of the Action. This dictates the formal parameters, whlie 
     * execute will affect an actual GameState.
     **/
    ActionDefinition action_def;

    /**
     * Creates a deep copy of the Action object.
     * \return A completely independant copy of the Action object.
     **/
    Action* clone();

protected:
    /**
     * Called by execute, to generate a collections of effects from effectDefinitions
     */
    std::vector<Effect*> *generate_effects();
};

} /* namespace engine */
#endif /* ACTION_H_ */
