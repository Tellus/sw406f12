/*
 * Game.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../Headers/Game.h"

using namespace std;

void Game::add_character(Character *character)
{
	if (this->characters.size() == 0)
		this->active = character;

	this->characters.push_back(character);

	cout << character->name << " (" << character->resource("health") <<
			" health, " << character->attribute("attack") << " attack, " <<
			character->attribute("defense") << " defense) has entered the "
					"arena!" << endl;
}

void Game::turn()
{
	cout << endl;

	/*
	 * Generate list of all possible actions:
	 */

	list<Action*> actions;
	for (list<Ability*>::iterator it = this->active->abilities.begin();
			it != this->active->abilities.end(); it++)
	{
		list<Action*> ability_actions = this->ability_table->generate(
				this->active, this->characters, (*it));
		actions.merge(ability_actions);
	}

	/*
	 * List generated, pick random move
	 */

	srand(time(NULL));

	int action_number = rand() % actions.size();

	list<Action*>::iterator it = actions.begin();

	for (int i = 0; i < action_number; i++)
		it++;

	/*
	 * Execute!
	 */

	(*it)->execute(true);

	for (list<Character*>::iterator it = this->characters.begin();
			it != this->characters.end(); it++)
	{
		(*it)->turnover(true);

		if ((*it)->dead)
		{
			this->characters.erase(it++);
		}
	}


	this->active = this->next_character(this->active);
}

void Game::execute(Action* action)
{

}

void Game::resolve()
{
	while (this->characters.size() > 1)
	{
		this->turn();
		Sleep(500);
	}
}

Character *Game::next_character(Character *current)
{
	for (list<Character*>::iterator it = this->characters.begin();
			it != this->characters.end(); it++)
	{
		if ((*it) == current)
		{
			it++;
			if (it != this->characters.end())
				return (*it);
			else
				return this->characters.front();
		}
	}

	return NULL;
}

Game::Game() {
	this->ability_table = new AbilityTable();
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}
