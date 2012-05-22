/*
 * PrimarchDoesNotExistException.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */ 

#ifndef PRIMARCH_DOES_NOT_EXIST_H_
#define PRIMARCH_DOES_NOT_EXIST_H_

#include "BaseException.h"
 
namespace engine {

/**
 * Generic exception used when a Primarch is requested from a PrimarchIndexer
 * and the Primarch was not found.
 **/
class PrimarchDoesNotExistException : public BaseException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	PrimarchDoesNotExistException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	virtual ~PrimarchDoesNotExistException() throw();
};
}

#endif
