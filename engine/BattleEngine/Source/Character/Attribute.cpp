/*
 * Attribute.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "Attribute.h"

namespace engine {

Attribute::Attribute()
{
	// TODO Auto-generated constructor stub

}

Attribute::~Attribute()
{
	// TODO Auto-generated destructor stub
}

Attribute::Attribute(float start)
{
    this->current = this->initial = start;
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

} /* namespace engine */
