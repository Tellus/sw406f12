/*
 * Effect.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef EFFECT_H_
#define EFFECT_H_

class Character;
// #include "Character.h"

namespace engine {

class Effect
{
public:
	Effect();
	virtual ~Effect();
	
	Character *target;
	Character *source;
	
	virtual void execute() = 0;
};

/**
 * Example effect.
 **/
class PhysicalDamage:Effect
{
public:
    virtual void execute();
};

} /* namespace engine */
#endif /* EFFECT_H_ */
