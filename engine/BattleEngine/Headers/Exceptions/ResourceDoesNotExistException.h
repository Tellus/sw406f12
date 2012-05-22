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
class ResourceDoesNotExistException : public PrimarchDoesNotExistException
{
public:
	ResourceDoesNotExistException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	virtual ~ResourceDoesNotExistException() throw();
};
}

#endif 
