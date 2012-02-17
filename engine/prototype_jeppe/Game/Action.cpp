/*
 * Action.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../Headers/Action.h"

using namespace std;

void Action::add_effect(Effect *effect)
{
	this->effects.push_back(effect);
}

void Action::execute(bool verbose)
{
	if (verbose)
		cout << this->output << endl;

	for (list<Effect*>::iterator it = this->effects.begin();
			it != this->effects.end(); it++)
	{
		(*it)->execute(verbose);
	}
}

Action::Action() {
	// TODO Auto-generated constructor stub
}

Action::Action(string output)
{
	this->output = output;
}

Action::~Action() {
	// TODO Auto-generated destructor stub
}

