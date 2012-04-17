/*
 * Ability.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITY_H_
#define ABILITY_H_

#include "EffectDefinition.h"
#include "Effect.h"
#include "RGR_Enum.h"
#include "vector"

#include <vector>

namespace engine {

class Ability
{
public:
	std::vector<EffectDefinition<Effect>> effects;
//	std::vector<RGR_Enum> targets;

	Ability();
	Ability(float cost_health, float cost_mana);
	virtual ~Ability();
	
	float cost_health, cost_mana;
	
	/**
	 * Adds an extra valid target to the Ability's list of targets.
	 * \param Any value from the RGR_Enum.
	 * \note Duplicates are ignored.
	 **/
	void add_target(RGR_Enum);
	
	/**
	 * Checks to see if the Ability already has a given target.
	 * \param tar Target to check for.
	 * \return True if the target is applied. False otherwise.
	 **/
    bool has_target(RGR_Enum tar);
    
    /**
     * Removes a target from the array.
     * \param tar Target to remove.
     **/
    void remove_target(RGR_Enum tar);
    
    /**
     * Toggles a target on the ability. If it's on, it's removed. Otherwise,
     * it's added.
     * \param tar The target to toggle.
     **/
    void toggle_target(RGR_Enum tar);
    
    /**
     * Set a completely new target mask.
     * \param tars New target (singular). Consider using set_targets(int).
     **/
    void set_targets(RGR_Enum tars);
	
	/**
	 * Set a completely new target mask.
	 * \param tars New mask.
	 **/
	void set_targets(int tars);
	
private:
    /**
     * Mask of targest allowed. Since we use an enum to pass valid targets, we
     * might as well extend to using bitwise operators instead of costly stl
     * containers.
     **/
    int targets;
};

} /* namespace engine */
#endif /* ABILITY_H_ */
