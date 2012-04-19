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
	this->ability->effects;
}

void Action::generate_effects()
{

	//Forskellige forsøg.. Men tror sq ikke de virker..
	/*
	for(std::vector<EffectDefinition<Effect> >::iterator i = this->ability->effects.begin();
		i != this->ability->effects.end(); i++)
	{
		for(std::vector<Effect>::iterator j = this->ability->effects.at(i); j != *i.end(); j++)
		{

		}
	}

	for(unsigned int i = 0; i < this->ability->effects.size(); i++)
	{
		for(unsigned int j = 0; j < this->ability->effects.size(); j++)
		{
			this->ability->effects[i];
		}
	}
*/
}


} /* namespace engine */
