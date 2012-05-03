/*
 * Effect.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "SexyEffect.h"

namespace testbattle{

SexyEffect::SexyEffect() : engine::Effect() {}

void SexyEffect::execute(Primarch* s, Primarch* t)
{
	engine::Character* schar = dynamic_cast<engine::Character*>(s);
	engine::Character* tchar = dynamic_cast<engine::Character*>(t);

	tchar->get_resource("Health")->regain(4);
	schar->get_resource("Mana")->deplete(10);
}

engine::Primarch* SexyEffect::clone(bool with_id)
{
	SexyEffect* se = new SexyEffect();

	if (with_id) se->id = this->id;

	// Specific cloning action.
	se->target_rgr = this->target_rgr;
	se->source_rgr = this->source_rgr;

	return se;
}

};
