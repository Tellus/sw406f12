/*
 * program.cpp
 *
 *  Created on: 14/02/2012
 *      Author: Ezphares
 */

#include <iostream>

#include "Headers/Game.h"

using namespace std;

int main(int argc, char *argv[])
{
	Game *game = new Game();
	game->add_character(new Character("Timmy", 5, 50, 1));
	game->add_character(new Character("Gorc the Orc", 100, 12, 8));
	game->add_character(new Character("Ser Rusty", 90, 8, 10));
	game->characters.back()->abilities.push_back(new Heal());


	game->resolve();

	return 0;
}
