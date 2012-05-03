/*
 * Primarch.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#include "Primarch.h"

namespace engine 
{

int Primarch::_id_counter=0;

Primarch::Primarch()
{
    // For new Primarchs, we get new id's.
    this->id = Primarch::get_new_id();
}

Primarch::Primarch(std::string name)
{
    this->name = name;
    this->id = Primarch::get_new_id();
}

int Primarch::get_new_id()
{
    return ++(Primarch::_id_counter);
}

}
