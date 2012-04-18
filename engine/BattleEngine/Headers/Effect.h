/*
 * Effect.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include "Primarch.h"

namespace engine {

class Effect
{
public:
	Effect();
	virtual ~Effect();
	
	Primarch *target;
	Primarch *source;
	
	virtual void execute() = 0;
};

} /* namespace engine */
#endif /* EFFECT_H_ */
