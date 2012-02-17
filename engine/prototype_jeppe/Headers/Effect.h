/*
 * Effect.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include "Character.h"

class Effect {
public:
	Character *source;
	Character *target;

	virtual void execute(bool verbose);

	Effect();
	virtual ~Effect();
};

#endif /* EFFECT_H_ */
