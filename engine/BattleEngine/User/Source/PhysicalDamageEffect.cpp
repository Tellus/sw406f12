/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t)
    : engine::Effect(s, t, "health", -20) {}

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount)
    : engine::Effect(s, t, "health", amount) {}

void PhysicalDamageEffect::execute(Primarch* s, Primarch* t)
{
	engine::Character *tchar = dynamic_cast<engine::Character*>(t);
	engine::Character *schar = dynamic_cast<engine::Character*>(s);

    engine::Attribute* str = schar->get_attribute("strength");

    tchar->get_resource("health")->decrease(str->get_current() * this->amount);
    
    // Get owner strength
    engine::Attribute* ostr = schar->get_attribute("strength");
    float dmg = ostr->get_current()/2 + 1; // Should be WeaponDmg + Str/2 + 1.
    
    // Get target defense.
    engine::Attribute* tdef = tchar->get_attribute("defense");
             
    // Final damage.
    float dam = dmg - tdef->get_current();
    
    tchar->get_resource("health")->decrease(dam * this->amount);
}

PhysicalDamageEffect::PhysicalDamageEffect() :
    Effect(engine::OWNER, engine::TARGET, "health", -20)
{
	this->name = "Physical Effect";
}

};
