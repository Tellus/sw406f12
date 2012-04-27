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

Effect::Effect(Primarch *source, Primarch *target)
{
    this->target = target;
    this->source = source;
}

Effect::Effect(const Effect& copy)
{
    // Currently, a copied effect is still just the same Effect without target
    // and source.
    this->source = copy.source;
    this->target = copy.target;
}

void Effect::execute()
{
    // TODO Useless stub.
    // TODO Reconsider a more elegant design.
    std::cout << "STUB EFFECT CALLED!\n";
}

void Effect::pretty_print()
{
    std::cout << "Effect: " << this->name << " (" << this->id << ")\n";
}

} /* namespace engine */
