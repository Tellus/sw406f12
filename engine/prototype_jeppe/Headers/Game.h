/*
 * Game.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef GAME_H_
#define GAME_H_

#include <list>
#include <time.h>
#include <cstdlib>
#include "Character.h"
#include "AbilityTable.h"
#include "Action.h"

using namespace std;

class Game {
public:
	list<Character*> characters;
	list<Action*> movesPossible;
	Character *active;
	AbilityTable *ability_table;

	void add_character(Character* character);
	void turn();
	void execute(Action* action);
	void resolve();
	Character *next_character(Character* current);

	Game();
	virtual ~Game();
};

#endif /* GAME_H_ */
