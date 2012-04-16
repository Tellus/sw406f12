/*
 * Ability.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITY_H_
#define ABILITY_H_

#include "EffectDefinition.h"
#include "RGR_Enum.h"
#include "vector"

#include <vector>

namespace engine {

enum target_options {SELF, ALLY, ENEMY, TEAM_ALLY, TEAM_ENEMY, ALL};

class Ability
{
public:
	std::vector<EffectDefinition*> effects;
	std::vector<target_options> targets;

	Ability();
	Ability(float cost_health, float cost_mana);
	virtual ~Ability();
	
	float cost_health, cost_mana;
	
protected:
    void add_target(engine::RGR_Enum tar);
};

} /* namespace engine */
#endif /* ABILITY_H_ */
