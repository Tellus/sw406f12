/*
 * Effect.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include "Primarch.h"
#include "RGR_Enum.h"

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
	Effect(RGR_Enum s, RGR_Enum t);
	virtual ~Effect();

	// Re-defined as pure virtual here to make it easier for dumb Effect programmers (... me, for example).
	virtual Primarch *clone(bool with_id = false) = 0;

	/**
	 * RGR to the target of the effect. We use the generalised form for Effects
	 * since they aren't realised until an Action needs to affect a GameState.
	 */
	RGR_Enum target_rgr;

	/**
	 * RGR of the source of the effect. We use the generalised form for Effects
	 * since they aren't realised until an Action needs to affect a GameState.
	 */
	RGR_Enum source_rgr;
	
	/**
	 * Makes the changes to source and target as defined by the subclassed
	 * Effect.
	 * \param in_state The state to make changes within.
	 **/
	virtual void execute(Primarch* s, Primarch* t) = 0;
	
	void pretty_print();
};

} /* namespace engine */
#endif /* EFFECT_H_ */
