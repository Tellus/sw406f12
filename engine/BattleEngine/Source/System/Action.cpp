/*
 * Action.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Action.h"

namespace engine {

Action::Action(Character *source, Ability *abil, Character *target)
{
    this->source_char = source;
    this->target_char = target;
    this->ability = abil;
}

Action::Action(Character *source, Ability *abil, RGR_Enum target)
{
    this->source_char = source;
    this->ability = abil;
    
    // Afvikle
}

Action::~Action() {
	// TODO Auto-generated destructor stub
}

} /* namespace engine */
