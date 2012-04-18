/*
 * Behaviour.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef BEHAVIOUR_H_
#define BEHAVIOUR_H_

#include "Character.h"

namespace engine {

class Behaviour {
public:
	Behaviour();
	virtual ~Behaviour();
	
	/**
	 * Calculates the piggy value depending on the premises given for the
	 * current Behaviour child class.
	 **/
	float get_piggy();
};

} /* namespace engine */
#endif /* BEHAVIOUR_H_ */
