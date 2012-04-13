/*
 * Ability.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITY_H_
#define ABILITY_H_

#include "EffectDefinition.h"

#include <vector>

namespace engine {

enum target_options {SELF, ALLY, ENEMY, TEAM_ALLY, TEAM_ENEMY, ALL};

class Ability {
public:
	std::vector<EffectDefinition*> effects;
	std::vector<target_options> targets;

	Ability();
	virtual ~Ability();
};

} /* namespace engine */
#endif /* ABILITY_H_ */
