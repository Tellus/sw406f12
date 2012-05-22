/*
 * ResourceDoesNotExistException.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#ifndef RESOURCE_DOES_NOT_EXIST_H_
#define RESOURCE_DOES_NOT_EXIST_H_

#include "PrimarchDoesNotExistException.h"

namespace engine {

/**
 * Used when an unknown resource is requested. This will also be thrown if you
 * request "Health" when you actually meant "health".
 **/
class ResourceDoesNotExistException : public PrimarchDoesNotExistException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	ResourceDoesNotExistException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	virtual ~ResourceDoesNotExistException() throw();
};
}

#endif 
