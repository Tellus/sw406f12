/*
 * PrimarchIndexer.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#pragma once

#include <list>
#include <algorithm>

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

	std::list<Primarch*> children;

	/**
	 * Retrieves a Primarch object by the Primarch ID.
	 * \param c_id Primarch ID of the Character.
	 * \return The first encountered Character object (should be the only one).
	 * \throws PrimarchDoesNotExistException if the requested ID was not found in the collection.
	 */
	Primarch* get_child_by_id(int c_id);

    /**
     * Adds a character to the list of characters. Will use the pointer given
     * without copying.
     **/
    void add_child(Primarch *to_add);

	bool has_child(int c_id);

private:
	void _init();
};

} /* namespace engine */
