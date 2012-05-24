/*
 * AbilityTable.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITYTABLE_H_
#define ABILITYTABLE_H_

#include <limits>

#include "PrettyPrinter.h"
#include "GameState.h"
#include "RGRIdentifier.h"
#include "Character.h"
#include "Action.h"

#include "Exceptions/NoValidActionException.h"

namespace engine {

/** 
 * AbilityTable is the proverbial meat 'n veg of the Engine. It handles the
 * tough decision-making for a Character by examining all possible outcomes of
 * using every possible Ability on every thinkable target.
 **/
class AbilityTable {
private:
    /**
     * Used to initialize data shared among the constructors.
     **/
    void _init();

protected:
    /**
     * Vector of Action objects, representing the Ability/Target combinations
     * to simulate.
     **/
    std::vector<Action*> *actions;
	
	/**
	 * Runs through all target combinations in an Ability, filtering out
	 * abilities that cannot be used by the source Character due to cost
	 * restrictions.
	 */
	void iterate_ability(Ability *src);

	/**
	 * Internally used to create the actions that are considered for final
	 * decisions.
	 **/
	std::vector<Action*> *create_actions(Character *from);

public:
    /**
     * Creates a new AbilityTable without a GameState to work on.
     **/
	AbilityTable();
	
	/**
	 * Creates a new AbilityTable instance and have it instantly calculate the
	 * highest valued action for a Character in a GameState.
	 * \param f_state The GameState to pull data from.
	 **/
	AbilityTable(GameState *f_state);
	
	/**
	 * \todo Implement.
	 **/
	virtual ~AbilityTable();
	
	/**
	 * The GameState that is used as a basis for calculations.
	 **/
	GameState *state;
	
	/**
	 * The best action, ready for use. The Action is stored like this to allow
	 * the calling environment to either allow a fully-automated execution by
	 * AbilityTable, or take care of final execution manually.
	 * \see AbilityTable::get_next_state()
	 **/
	Action *best_action;
	
	/**
	 * The best next state, as determined by an execution on best_action.
	 */
	GameState *best_state;

	/**
	 * Runs the AbilityTable calculations and creates a new GameState wherein
	 * the current Character has taken the best action available to them.
	 * \return A new GameState.
	 * \note Only the things that can be affected by an Effect execution are
	 * modified. Turn order and current Character will not be directly changed
	 * by AbilityTable.
	 **/
    GameState *get_next_state();
    
    /**
     * Executes an action. Use this as a force scenario, when a condition for
     * event has been met.
     **/
    GameState* force_action(ActionDefinition* action);
    
    /**
     * Simulates an action on a cloned state and returns the state's active
     * character's resulting piggy value.
     * \param a The Action to perform.
     * \return A standard piggy value.
     **/
    float get_action_piggy(Action *a);
};

} /* namespace engine */
#endif /* ABILITYTABLE_H_ */
