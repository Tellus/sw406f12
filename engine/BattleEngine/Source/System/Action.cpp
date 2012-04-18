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
    
    // Afvikle
}

Action::~Action() {
	// TODO Auto-generated destructor stub
}

} /* namespace engine */
