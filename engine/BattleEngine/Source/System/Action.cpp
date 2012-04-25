/*
 * Action.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Action.h"

namespace engine {

Action::Action(Primarch *source, Ability *abil, Primarch *target)
{
    this->source = source;
    this->target = target;
    this->ability = abil;
}

Action::Action(Primarch *source, Ability *abil, RGR_Enum target)
{
    this->source = source;
    this->ability = abil;
    
    // Afvikle this->execute();
}

Action::~Action() {
	// TODO Auto-generated destructor stub
}

void Action::execute()
{
	this->generate_effects();
}

void Action::generate_effects()
{
	std::vector<Effect*> *tmp = &this->ability->effects;
	Effect *eff;
	for(std::vector<Effect*>::iterator i = tmp->begin(); i != tmp->end(); i++)
	{
	    eff = *i;
		eff->clone(source, target);
	}
}

} /* namespace engine */
