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
	std::vector<EffectDefinition<Effect> > effects;
//	std::vector<RGR_Enum> targets;

	Ability();
	Ability(float cost_health, float cost_mana);
	virtual ~Ability();
	
	float cost_health, cost_mana;
	
    RGR_List targets;
};

} /* namespace engine */
#endif /* ABILITY_H_ */
