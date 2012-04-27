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

Primarch::Primarch(const Primarch& copy)
{
    this->name = copy.name;
    // For cloned Primarchs, we copy the id, so the same Primarch entity can be
    // referenced across different GameState objects. This cannot be done by
    // pointers.
    this->id = copy.id;
}

int Primarch::get_new_id()
{
    return ++(Primarch::_id_counter);
}

}
