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
    this->_init();
    
    this->cost_health = this->cost_mana = 0;
}

Ability::Ability(float cost_health, float cost_mana)
{
    this->_init();
    
    this->cost_health = cost_health;
    this->cost_mana = cost_mana;
}

void Ability::_init()
{
    this->effects = std::vector<engine::Effect*>();
}

Ability::~Ability()
{
	// TODO Auto-generated destructor stub
}

} /* namespace engine */
