/*
 * EffectDefinition.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */
#ifndef EFFECTDEFINITION_H_
#define EFFECTDEFINITION_H_

#include "Primarch.h"
#include "Effect.h"

namespace engine {

template <class T> class EffectDefinition
{
public:
	EffectDefinition();
	virtual ~EffectDefinition();
	
	T spawn(Primarch *source, Primarch *target);
};

} /* namespace engine */
#endif /* EFFECTDEFINITION_H_ */
