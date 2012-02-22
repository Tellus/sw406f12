/*
 * InstantHeal.cpp
 *
 *  Created on: 22/02/2012
 *      Author: Ezphares
 */

#include "../../Headers/InstantHeal.h"

void InstantHeal::execute(bool verbose)
{
	this->target->resource_regain("health", this->amount, verbose);
}

InstantHeal::InstantHeal(Character *source, Character *target, double amount) {
	this->source = source;
	this->target = target;
	this->amount = amount;
}

InstantHeal::~InstantHeal() {
	// TODO Auto-generated destructor stub
}

