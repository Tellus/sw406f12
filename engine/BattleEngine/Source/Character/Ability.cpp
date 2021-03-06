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
    this->cost_health = this->cost_mana = 0;

	this->name = this->get_default_name("Ability");
}

Ability::Ability(std::string name, float cost_health, float cost_mana) :
    Primarch(name)
{
    this->cost_health = cost_health;
    this->cost_mana = cost_mana;
}

Primarch* Ability::clone(bool with_id)
{
	Ability* to_ret = new Ability(this->name, this->cost_health, this->cost_mana);

	Effect* new_eff;

	for (std::vector<Effect*>::const_iterator eff_iter = this->effects.begin();
         eff_iter != this->effects.end();
         eff_iter++)
    {
		new_eff = dynamic_cast<Effect*>((*eff_iter)->clone(with_id));
		if (new_eff == NULL)
		{
			throw "Bad Effect cast!";
		}
		to_ret->add_effect(new_eff);
    }

	to_ret->rgr_list = this->rgr_list;

	return to_ret;
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
    std::cout << "\n" << "Effects (" << this->effects.size() << "):\n";
    for (std::vector<Effect*>::iterator eff_iter = this->effects.begin();
         eff_iter != this->effects.end();
         eff_iter++)
    {
        (*eff_iter)->pretty_print();
    }
}

float Ability::get_value()
{
	float ret = 0;
	
	for (std::vector<Effect*>::iterator iter = this->effects.begin();
		 iter != this->effects.end();
		 iter++)
	{
		ret += (*iter)->get_value();
	}

	return ret;
}

void Ability::modify(float amount)
{
	// No effect. Could be a ratio, crit... something?
}

void Ability::add_effect(Effect* to_add)
{
    this->effects.push_back(to_add);
}

} /* namespace engine */
