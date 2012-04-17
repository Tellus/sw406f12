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
	// Note you'll probably mess things up if you don't use non-abstract
	// objects during new EffDeff additions.
    this->effects = std::vector<engine::EffectDefinition<Effect>>();
    this->targets = 0;
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
    // OR'ing it several times has no effect. No existance check is needed.
    this->targets |= tar;
}

void Ability::remove_target(engine::RGR_Enum tar)
{
    // XOR will only remove it if it already exists, so we check existance.
    if (this->has_target(tar)) this->targets ^= tar;
    else return;
}

bool Ability::has_target(engine::RGR_Enum tar)
{
    return ((this->targets & tar) == tar);
}

void Ability::toggle_target(engine::RGR_Enum tar)
{
    this->targets ^= tar;
}

void Ability::set_targets(int tar)
{
    this->targets = tar;
}

void Ability::set_targets(RGR_Enum tar)
{
    this->targets = tar;
}

} /* namespace engine */
