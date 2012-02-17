/*
 * Action.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <list>
#include "Effect.h"

using namespace std;

class Action {
public:
	list<Effect> effects;

	void execute();

	Action();
	virtual ~Action();
};

#endif /* ACTION_H_ */
