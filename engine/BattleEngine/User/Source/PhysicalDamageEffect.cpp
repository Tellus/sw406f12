/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "PhysicalDamageEffect.h"

namespace testbattle{

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t)
    : engine::Effect(s, t, "Health", -20) {}

PhysicalDamageEffect::PhysicalDamageEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount)
    : engine::Effect(s, t, "Health", amount) {}

void PhysicalDamageEffect::execute(Primarch* s, Primarch* t)
{
	engine::Character *tchar = dynamic_cast<engine::Character*>(t);
	engine::Character *schar = dynamic_cast<engine::Character*>(s);

    engine::Attribute* str = schar->get_attribute("Strength");

    tchar->get_resource("Health")->decrease(str->get_current() * this->amount);
}

PhysicalDamageEffect::PhysicalDamageEffect() :
    Effect(engine::OWNER, engine::TARGET, "Health", -20)
{
	this->name = "Physical Effect";
}

};
