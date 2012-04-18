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

public:
	AbilityTable();
	virtual ~AbilityTable();
	
	void create_actions(Character *from);
};

} /* namespace engine */
#endif /* ABILITYTABLE_H_ */
