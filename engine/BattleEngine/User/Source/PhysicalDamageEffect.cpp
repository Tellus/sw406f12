/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t)
    : engine::Effect(s, t, "health", 1) {this->name = "Physical damage";}

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount)
    : engine::Effect(s, t, "health", amount) {this->name = "Physical damage";}

void PhysicalDamageEffect::execute(Primarch* s, Primarch* t)
{
    // std::cout << "PhysicalDamage calculation.\n";

	engine::Character *tchar = dynamic_cast<engine::Character*>(t);
	engine::Character *schar = dynamic_cast<engine::Character*>(s);

    // std::cout << "Characters cast.\n";

    float dam = std::max(schar->get_attribute("attack_power")->get_current() -
                tchar->get_attribute("defense")->get_current(), 0.0f);
                
    // std::cout << "Final Physical Damage: " << dam << '\n';
                
    tchar->get_resource("health")->decrease(dam);
    
    // std::cout << "Applied.\n";
}

PhysicalDamageEffect::PhysicalDamageEffect() :
    Effect(engine::OWNER, engine::TARGET, "health", -20)
{
	this->name = "Physical Effect";
}

engine::Primarch* PhysicalDamageEffect::clone(bool with_id)
{
    PhysicalDamageEffect* c = new PhysicalDamageEffect();
    if (with_id) c->id = this->id;
    return c;
}

};
