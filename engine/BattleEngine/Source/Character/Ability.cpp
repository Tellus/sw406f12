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
    this->effect_defs = std::vector<engine::EffectDefinition>();
    this->legal_targets = std::vector<engine::RGR_Enum>();
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

void Ability::add_target(engine::RGR_Enum tar)
{
    this->legal_targets.push_back(tar);
}

} /* namespace engine */
