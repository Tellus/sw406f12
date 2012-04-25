/*
 * Effect.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Effect.h"

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

void Effect::execute()
{
    // TODO Useless stub.
    // TODO Reconsider a more elegant design.
}

} /* namespace engine */
