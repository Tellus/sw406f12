/*
 * Effect.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Effect.h"
#include <iostream>

namespace engine {

Effect::Effect()
{
	// TODO Auto-generated constructor stub

}

Effect::~Effect()
{
	// TODO Auto-generated destructor stub
}

Effect::Effect(RGR_Enum source, RGR_Enum target)
{
    this->target_rgr = target;
    this->source_rgr = source;
}

void Effect::pretty_print()
{
    std::cout << "Effect: " << this->name << " (" << this->id << ")\n";
}

} /* namespace engine */
