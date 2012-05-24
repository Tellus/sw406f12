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
	
	/**
	 * Creates an effect with a flat value change.
	 * \param s The source of the Effect. Typically OWNER or SELF.
	 * \param t The target of the Effect (what to *affect*).
	 * \param member Name of the member to modify. Typically a Resource, but
	 * can be anything contained in the target Primarch.
	 * \param amount Depending on implementation, either magnitude or flat
	 * value. In a base Effect, this is the flat value to modify member with.
	 **/
	Effect(RGR_Enum s, RGR_Enum t, std::string member, float amount);
	
    /**
     * \todo Implement.
     **/
	virtual ~Effect();

    /**
     * Inherited from Primarch. Creates an exact copy of the Effect.
     * \param with_id If true, will make the new Effect identical (in regards
     * to name and Id) to the original. If false, a new Id is generated.
     **/
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
	 * Effect OR a flat change based on the amount and member.
	 * \param s The source Character.
	 * \param t The target Character to be affected.
	 **/
	virtual void execute(Primarch* s, Primarch* t);
	
	/**
	 * Outputs the Effect in a human-readable format to stdout.
	 **/
	virtual void pretty_print();

    /**
     * Returns the Effect's current magnitude or flat value.
     * \return The Effect's current magnitude or flat value.
     **/
	float get_value();

    /**
     * Modifies the Effect's value (i.e. magnitude or flat amount).
     **/
	void modify(float amount);
};

} /* namespace engine */
#endif /* EFFECT_H_ */
