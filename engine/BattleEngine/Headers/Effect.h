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
	Effect(RGR_Enum s, RGR_Enum t, std::string member, float amount);
	virtual ~Effect();

	virtual Primarch *clone(bool with_id = false);

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
	 * The name of the Primarch member of the target to affect.
	 **/
	std::string member;

	/**
	 * The amount to change the member with on execute.
	 **/
	float amount;

	/**
	 * Makes the changes to source and target as defined by the subclassed
	 * Effect.
	 * \param in_state The state to make changes within.
	 **/
	virtual void execute(Primarch* s, Primarch* t);
	
	virtual void pretty_print();

	float get_value();

	void modify(float amount);
};

} /* namespace engine */
#endif /* EFFECT_H_ */
