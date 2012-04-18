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

template <class T> T EffectDefinition<T>::spawn(Character *source, Character *target)
{
    return new T(source, target);
}

} /* namespace engine */
