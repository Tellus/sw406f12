/*
 * Action.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <list>
#include <iostream>
#include "Effect.h"

using namespace std;

class Action {
public:
	list<Effect*> effects;
	string output;

	void add_effect(Effect* effect);
	void execute(bool verbose);

	Action();
	Action(string output);
	virtual ~Action();
};

#endif /* ACTION_H_ */
