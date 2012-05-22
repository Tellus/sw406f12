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
class PrimarchDoesNotExistException : public BaseException
{
public:
	PrimarchDoesNotExistException();
	PrimarchDoesNotExistException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	virtual ~PrimarchDoesNotExistException() throw();
};
}

#endif
