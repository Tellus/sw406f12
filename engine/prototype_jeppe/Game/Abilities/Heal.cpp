/*
 * Heal.cpp
 *
 *  Created on: 21/02/2012
 *      Author: Ezphares
 */

#include "../../Headers/Heal.h"

Heal::Heal() {
		this->id = "heal";
		this->targets.push_back(self);
		this->output = "{s} used heal on {t}!";
}

Heal::~Heal() {
	// TODO Auto-generated destructor stub
}

