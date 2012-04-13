/*
 * GameState.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Character.h"
#include "Behaviour.h"
#include "AbilityTable.h"

namespace engine {

class GameState {
public:
	GameState();
	virtual ~GameState();
};

} /* namespace engine */
#endif /* GAMESTATE_H_ */
