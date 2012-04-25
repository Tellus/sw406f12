/*
 * EffectDefinition.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "EffectDefinition.h"

namespace engine {

template <class T> EffectDefinition<T>::EffectDefinition() {
	Effect *test = new T();
}

template <class T> EffectDefinition<T>::~EffectDefinition() {
	// TODO Auto-generated destructor stub
}

template <class T> T EffectDefinition<T>::spawn(Primarch *source, Primarch *target)
{
    return T(source, target);
}

template Effect EffectDefinition<Effect>::spawn(Primarch *source, Primarch *target);

} /* namespace engine */
