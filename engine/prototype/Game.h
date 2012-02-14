/*
 * Game.h
 *
 *  Created on: 14/02/2012
 *      Author: Ezphares
 */

#ifndef GAME_H_
#define GAME_H_

#include "External/Character.h"
#include <list>

class Game {
public:
	std::list<Character> characters;

	Game();
	virtual ~Game();
};

#endif /* GAME_H_ */
