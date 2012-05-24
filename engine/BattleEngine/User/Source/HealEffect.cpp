/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "HealEffect.h"

namespace testbattle{

HealEffect::HealEffect(engine::RGR_Enum s, engine::RGR_Enum t) :
    engine::Effect(s, t, "health", 10) {this->name = "Heal";}

HealEffect::HealEffect(engine::RGR_Enum s, engine::RGR_Enum t, float amount) :
    engine::Effect(s, t, "health", amount) {this->name = "Heal";}

HealEffect::HealEffect() :
    engine::Effect(engine::OWNER, engine::TARGET, "health", 10) {this->name = "Heal";}

void HealEffect::execute(engine::Primarch* s, engine::Primarch* t)
{
    std::cout << "Heal calculation.\n";
    
    engine::Character* tc = dynamic_cast<engine::Character*>(t);
    tc->get_resource("health")->increase(this->amount);
}

engine::Primarch* HealEffect::clone(bool with_id)
{
    HealEffect* h = new HealEffect();
    if (with_id) h->id = this->id;
    return h;
}

} /* End namespace */
