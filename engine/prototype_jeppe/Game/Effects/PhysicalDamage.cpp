/*
 * PhysicalDamage.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../../Headers/PhysicalDamage.h"

void PhysicalDamage::execute(bool verbose)
{
	this->target->resource_deplete("health", this->source->attribute("attack") /
			this->target->attribute("defense") * amount, verbose);
}

PhysicalDamage::PhysicalDamage(Character *source, Character *target,
		double amount)
{
	this->target = target;
	this->source = source;
	this->amount = amount;
	// TODO Auto-generated constructor stub

}

PhysicalDamage::~PhysicalDamage() {
	// TODO Auto-generated destructor stub
}

