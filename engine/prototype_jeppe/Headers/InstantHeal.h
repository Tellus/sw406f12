/*
 * InstantHeal.h
 *
 *  Created on: 22/02/2012
 *      Author: Ezphares
 */

#ifndef INSTANTHEAL_H_
#define INSTANTHEAL_H_

#include "Effect.h"

class InstantHeal: public Effect {
public:
	double amount;

	void execute(bool verbose);

	InstantHeal(Character *source, Character *target, double amount);
	virtual ~InstantHeal();
};

#endif /* INSTANTHEAL_H_ */
