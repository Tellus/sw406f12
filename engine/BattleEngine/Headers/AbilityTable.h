/*
 * AbilityTable.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITYTABLE_H_
#define ABILITYTABLE_H_

#include "Character.h"
#include "Action.h"

namespace engine {

class AbilityTable {
protected:
    /**
     * Vector of Action objects, representing the Ability/Target combinations
     * to simulate.
     **/
    std::vector<Action> actions;
	
	/**
	 * Runs through all target combinations in an Ability, filtering out
	 * abilities that cannot be used by the source Character due to cost
	 * restrictions.
	 */
	void iterate_ability(Ability *src);

public:
	AbilityTable();
	virtual ~AbilityTable();
	
	void create_actions(Character *from);
};

} /* namespace engine */
#endif /* ABILITYTABLE_H_ */
