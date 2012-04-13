/*
 * Character.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Attribute.h"
#include "Ability.h"
#include "ContinouosEffect.h"
#include "Resource.h"

namespace engine {

class Character {
public:
	Character();
	virtual ~Character();
};

} /* namespace engine */
#endif /* CHARACTER_H_ */
