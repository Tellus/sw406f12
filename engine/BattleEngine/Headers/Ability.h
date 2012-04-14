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

<<<<<<< HEAD
enum target_options {SELF, ALLY, ENEMY, TEAM_ALLY, TEAM_ENEMY, ALL};

class Ability {
=======
class Ability
{
>>>>>>> d22b1314e2f5406186daab34289994c653fb9e77
public:
	std::vector<EffectDefinition*> effects;
	std::vector<target_options> targets;

	Ability();
	Ability(float cost_health, float cost_mana);
	virtual ~Ability();
	
	float cost_health, cost_mana;
	
	std::vector<engine::RGR_Enum> legal_targets;
	
	std::vector<engine::EffectDefinition> effect_defs;
	
protected:
    void add_target(engine::RGR_Enum tar);
};

} /* namespace engine */
#endif /* ABILITY_H_ */
