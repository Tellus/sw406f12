/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "HealEffect.h"

namespace testbattle{

HealEffect::HealEffect() : engine::Effect() {}

HealEffect::HealEffect(engine::RGR_Enum s, engine::RGR_Enum t) :
    engine::Effect(s, t)
{
    // Empty, see intializer.
}

void HealEffect::execute(engine::Primarch* s, engine::Primarch* t)
{
	engine::Character* tchar = dynamic_cast<engine::Character*>(t);
	engine::Character* schar = dynamic_cast<engine::Character*>(s);

    // Heals for 40 health.
	tchar->get_resource("Health")->regain(40);
	// Costs a bit, too.
	schar->get_resource("Mana")->deplete(20);
}

engine::Primarch* HealEffect::clone(bool with_id)
{
	HealEffect* he = new HealEffect(this->source_rgr, this->target_rgr);

	return he;
}

};
