/*
 * PrimarchIndexer.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#ifndef PRIMARCH_INDEXER_H_
#define PRIMARCH_INDEXER_H_

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
    /**
     * Creates and initialises a new PrimarchIndexer.
     **/
	PrimarchIndexer();
	
	/** 
	 * \todo Implement?
	 **/
	virtual ~PrimarchIndexer();

    /**
     * List of the children Primarchs that this indexer contains.
     **/
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

    /**
     * Checks to see if a particular child is within this indexer.
     * \param c_id Primarch Id of the child to find.
     **/
	bool has_child(int c_id);

private:
    /**
     * Private initialiser method.
     **/
	void _init();
};

} /* namespace engine */

#endif
