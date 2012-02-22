/*
 * PhysicalDamage.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef PHYSICALDAMAGE_H_
#define PHYSICALDAMAGE_H_

#include "Effect.h"

class PhysicalDamage : public Effect {
public:
	double amount;

	void execute(bool verbose);

	PhysicalDamage(Character *source, Character *target, double amount);
	virtual ~PhysicalDamage();
};

#endif /* PHYSICALDAMAGE_H_ */
