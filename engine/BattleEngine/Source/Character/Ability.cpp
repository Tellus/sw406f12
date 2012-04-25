/*
 * Ability.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Ability.h"

namespace engine {

Ability::Ability()
{
    this->effects = std::vector<engine::Effect*>();
    this->cost_health = this->cost_mana = 0;
}

Ability::Ability(float cost_health, float cost_mana)
{
    Ability();
    this->cost_health = cost_health;
    this->cost_mana = cost_mana;
}

Ability::~Ability()
{
	// TODO Auto-generated destructor stub
}

} /* namespace engine */
