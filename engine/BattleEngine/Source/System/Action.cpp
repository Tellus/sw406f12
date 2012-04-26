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
    std::cout << "Action execution started.\n";

	std::vector<Effect*> *effects = this->generate_effects();
	for (std::vector<Effect*>::iterator iter = effects->begin(); iter != effects->end(); iter++)
	{
	    std::cout << "\tExecuting effect.\n";
	    Effect* f = *iter;
	    f->execute();
	}
}

std::vector<Effect*> *Action::generate_effects()
{
	std::vector<Effect*> *tmp = &this->ability->effects;
	std::vector<Effect*> *out = new std::vector<Effect*>();;
	Effect *eff;
	
	std::cout << "Cloning " << tmp->size() << " effects.\n";
	
	for(std::vector<Effect*>::iterator i = tmp->begin(); i != tmp->end(); i++)
	{
	    eff = *i;
		out->push_back(eff->clone(source, target));
	}
	return out;
}

} /* namespace engine */
