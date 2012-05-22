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
class NoValidActionException : public BaseException
{
public:
	NoValidActionException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~NoValidActionException() throw();
};
}

#endif
