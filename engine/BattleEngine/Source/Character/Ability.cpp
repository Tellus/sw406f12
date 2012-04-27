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

Ability::Ability(const Ability& copy)
{
    this->_init();
    
    // Set basics.
    this->cost_health = copy.cost_health;
    this->cost_mana = copy.cost_mana;
    
    // Get effects.
    for (std::vector<Effect*>::const_iterator eff_iter = copy.effects.begin();
         eff_iter != copy.effects.end();
         eff_iter++)
    {
        effects.push_back(new Effect(**eff_iter));
    }
    
    // Get targets.
    // Try a simple variant drawn from implementation.

    for (std::list<RGR_Enum>::const_iterator rgr_iter = copy.rgr_list.begin();
         rgr_iter != copy.rgr_list.end();
         rgr_iter++)
    {
        this->add_rgr(*rgr_iter);
    }
}

void Ability::_init()
{
    this->effects = std::vector<engine::Effect*>();
}

Ability::~Ability()
{
	// TODO Auto-generated destructor stub
}

void Ability::pretty_print()
{
    std::cout << "Ability: " << this->name << " (" << this->id << ")\n";
    std::cout << "Valid targets: ";
    for (std::list<RGR_Enum>::iterator rgr_iter = this->rgr_list.begin();
         rgr_iter != this->rgr_list.end();
         rgr_iter++)
    {
        std::cout << RGR_List::to_string(*rgr_iter) << " ";
    }
    std::cout << "\n" << "Effects:\n";
    for (std::vector<Effect*>::iterator eff_iter = this->effects.begin();
         eff_iter != this->effects.end();
         eff_iter++)
    {
        (*eff_iter)->pretty_print();
    }
}

} /* namespace engine */
