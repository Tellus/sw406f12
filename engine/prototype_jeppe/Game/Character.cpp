/*
 * Character.cpp
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#include "../Headers/Character.h"

using namespace std;

double Character::attribute(string id)
{
	for (list<Attribute*>::iterator it = this->attributes.begin();
			it != this->attributes.end(); it++)
	{
		if ((*it)->name.compare(id) == 0)
			return (*it)->current;
	}

	return -1.0;
}

double Character::resource(string id)
{
	for (list<Resource*>::iterator it = this->resources.begin();
			it != this->resources.end(); it++)
	{
		if ((*it)->name.compare(id) == 0)
			return (*it)->current;
	}

	return -1.0;
}

void Character::resource_deplete(string id, double amount, bool verbose)
{
	for (list<Resource*>::iterator it = this->resources.begin();
			it != this->resources.end(); it++)
	{
		if ((*it)->name.compare(id) == 0)
		{
			(*it)->deplete(amount);
			if (verbose)
				cout << this->name << " lost " << amount << " " << id << "! ("
						<< (*it)->current << " left) " << endl;
		}
	}
}

void Character::resource_regain(string id, double amount, bool verbose)
{
	for (list<Resource*>::iterator it = this->resources.begin();
			it != this->resources.end(); it++)
	{
		if ((*it)->name.compare(id) == 0)
		{
			(*it)->regain(amount);
			if (verbose)
				cout << this->name << " gained " << amount << " " << id
						<< "! (up to " << (*it)->current << ")" << endl;
		}
	}
}

void Character::turnover(bool verbose)
{
	if (this->resource("health") <= 0.0)
	{
		this->dead = true;
		if (verbose)
			cout << this->name << " died!" << endl;
	}
}

Character::Character() {
	// TODO Auto-generated constructor stub

}

Character::Character(string name, double health, double attack, double defense)
{
	this->name = name;
	this->resources.push_back(new Resource("health", health));
	this->attributes.push_back(new Attribute("attack", attack));
	this->attributes.push_back(new Attribute("defense", defense));

	this->abilities.push_back(new Attack());
	this->dead = false;
}

Character::~Character() {
	for (list<Attribute*>::iterator it = this->attributes.begin();
			it != this->attributes.end(); it++)
		delete (*it);

	for (list<Resource*>::iterator it = this->resources.begin();
			it != this->resources.end(); it++)
		delete (*it);

	for (list<Ability*>::iterator it = this->abilities.begin();
			it != this->abilities.end(); it++)
		delete (*it);
}
