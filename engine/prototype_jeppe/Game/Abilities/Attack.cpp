/*
 * Attack.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../../Headers/Attack.h"

Attack::Attack()
{
	this->id = "attack";
	this->targets.push_back(enemy);
	this->output = "{s} attacks {t}!";
}

Attack::~Attack()
{
	// TODO Auto-generated destructor stub
}
