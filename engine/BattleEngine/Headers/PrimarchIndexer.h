/*
 * PrimarchIndexer.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#pragma once

#include <list>

#include "Character.h"

#include "Exceptions/PrimarchDoesNotExistException.h"

namespace engine
{

/**
 * Interface class (with implementations) for easily indexing
 * and working with lists of Primarchs. Primary usages are within
 * Engine (for its base_characters list) and GameState (for the
 * corresponding characters list).
 **/
class PrimarchIndexer
{
public:
	PrimarchIndexer();
	virtual ~PrimarchIndexer();

	std::list<Character*> characters;

	Character* get_character_by_id(int c_id);

private:
	void _init();
};

} /* namespace engine */
