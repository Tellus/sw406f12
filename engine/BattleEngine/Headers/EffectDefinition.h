/*
 * EffectDefinition.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */
#ifndef EFFECTDEFINITION_H_
#define EFFECTDEFINITION_H_

#include "Effect.h"
class Character;

namespace engine {

template <class T> class EffectDefinition
{
public:
	EffectDefinition();
	virtual ~EffectDefinition();
	
	T spawn(Character *source, Character *target);
};

} /* namespace engine */
#endif /* EFFECTDEFINITION_H_ */
