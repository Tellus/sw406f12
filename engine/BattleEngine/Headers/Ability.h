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
#include "RGR_List.h"

#include <vector>

namespace engine {

class Ability : public RGR_List
{
public:
    /**
     * The effects applied when an ability is used. It is preferred that you
     * use Effect::clone() when you need an effects rather than use it directly.
     **/
	std::vector<Effect*> effects;
//	std::vector<RGR_Enum> targets;

	Ability();
	Ability(float cost_health, float cost_mana);
	virtual ~Ability();
	
	float cost_health, cost_mana;
	
    RGR_List targets;
    
    /**
     * Retrieves the effect vector, specialised to a specific target.
     **/
    std::vector<Effect*> get_effects(Primarch *target);
    
private:
    /**
     * Used by constructors for the initializations shared between them all.
     **/
    void _init();
};

} /* namespace engine */
#endif /* ABILITY_H_ */
