/*
 * FullBehaviour.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */

#ifndef FULL_BEHAVIOUR_H_
#define FULL_BEHAVIOUR_H_

#include "Behaviour.h"
#include "BehaviourRatio.h"

#include <string>
#include <list>

namespace engine {

/** 
 * FullBehaviour does what Behaviour was intended to in langname. Using a set of
 * ratios, it calculates the value of any game state.
 **/
class FullBehaviour : public engine::Behaviour
{
public:
    /**
     * Creates and initialises a new FullBehaviour object.
     **/
	FullBehaviour();
	
	/**
	 * \todo Implement.
	 **/
	virtual ~FullBehaviour();
	
	/**
	 * Calculates the piggy value depending on the premises given for the
	 * current Behaviour child class.
	 **/
	virtual float get_piggy(GameState* from);

	/**
	 * List of the ratios that encompass the behaviour.
	 * They are sequencially called when determining 
	 */
	std::list<BehaviourRatio*> ratios;

	/**
	 * Adds a new ratio to the collection.
	 **/
	void add_ratio(BehaviourRatio* add);

	/**
	 * Removes a ratio, by name, from the collection.
	 **/
	void remove_ratio(std::string name);

    /**
     * Clones the FullBehaviour with all of its ratios.
     * \return A new FullBehaviour instance with copies of all its contained
     * BehaviourRatios.
     **/
	Behaviour* clone();

private:
    /**
     * Private initialiser method.
     **/
	void _init();
};

} /* namespace engine */

#endif
