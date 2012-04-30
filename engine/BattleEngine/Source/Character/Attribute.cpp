/*
 * Attribute.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Attribute.h"

namespace engine
{

Attribute::Attribute()
{
	// TODO Auto-generated constructor stub
}

Attribute::Attribute(float start)
{
    this->set_initial(start);
}

Attribute::Attribute(int initial)
{
    this->set_initial((float)initial);
}

Attribute::Attribute(const Attribute& copy)
{
	this->current = copy.current;
	this->initial = copy.initial;
}

Attribute::~Attribute()
{
	// Nothing to clean...
}

void Attribute::set_initial(float init)
{
    this->current = this->initial = init;
}

void Attribute::modify(float amount)
{
	this->current += amount;
}

void Attribute::increase(float amount)
{
    this->current += amount;
}

void Attribute::decrease(float amount)
{
    this->current -= amount;
}

void Attribute::change(float amount)
{
    if (amount < 0)
        this->decrease(amount);
    else if (amount > 0)
        this->increase(amount);
    else return;
}

void Attribute::reset()
{
    this->current = this->initial;
}

float Attribute::get_current()
{
	return this->current;
}

void Attribute::pretty_print()
{
    std::cout << "Attribute: " << this->name << " (" << this->id << ")\n";
}

} /* namespace engine */
