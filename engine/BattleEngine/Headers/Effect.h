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

/**
 * Generic effect class. Contrary to the original design, the Effect generates
 * itself, thus working as its own EffectDefinition. This was done to avoid an
 * unhealthy amount of classes in the other alternative (separate subclasses of
 * EffectDefinition defeats its purpose).
 **/
class Effect : public Primarch
{
public:
    /**
     * Creates an unusable Effect, useful as an EffectDefinition. While it may
     * be usable, it is not guaranteed in the API.
     **/
	Effect();
	
	/**
	 * Copy-constructor, used for creating deep mirror copies during GameState
	 * cloning.
	 **/
	Effect(const Effect& copy);
	
	/**
	 * Creates a usable Effect, with a source and target (our pre-determined
	 * required parameters for any type of effect).
	 * \param source Pointer to the Primarch that *causes* the effect.
	 * \param target Pointer to the Primarch that is *affected* by the effect.
	 **/
	Effect(Primarch *source, Primarch *target);
	virtual ~Effect();
	
	/**
	 * The target of the effect. This is what should be affected by the...
	 * effects. Note the use of a Primarch supertype to avoid circular
	 * references to Character (through Character->Ability->Effect->Character),
	 * but also to (unintentionally) enable affecting any other Primarch
	 * subclass (which could be made out to be Items, Resource, Attributes and
	 * the like) directly.
	 **/
	Primarch *target;
	
	/**
	 * The source of the effect. May be primarily used by the Engine and
	 * frontend to output something about the source, but often you'll find that
	 * effects rely on some characteristic about their source (FF: physical
	 * damage relies on the source's Strength Attribute).
	 **/
	Primarch *source;
	
	/**
	 * Makes the changes to source and target as defined by the subclassed
	 * Effect.
	 **/
	virtual void execute();
	
	void pretty_print();
};

} /* namespace engine */
#endif /* EFFECT_H_ */
