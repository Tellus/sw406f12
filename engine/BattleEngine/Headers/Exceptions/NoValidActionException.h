/*
 * NoValidActionException.h
 *
 *  Created on: 05/05/2012
 *      Author: Johannes
 */ 

#ifndef NO_VALID_ACTION_H_
#define NO_VALID_ACTION_H_

#include "BaseException.h"
 
namespace engine {

/**
 * Thrown if AbilityTable reaches a juncture where no valid action was possible
 * when going through the matrix of Ability*Target pairs.
 **/
class NoValidActionException : public BaseException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	NoValidActionException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~NoValidActionException() throw();
};
}

#endif
