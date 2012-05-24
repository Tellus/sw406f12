/*
 * NullParameterException.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#ifndef NULL_PARAM_EXCEPTION_H_
#define NULL_PARAM_EXCEPTION_H_

#include "BaseException.h"
 
namespace engine {

/**
 * Exception used if a null value was passed in a place where it would be a bad
 * idea to do so.
 **/
class NullParameterException : public BaseException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	NullParameterException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~NullParameterException() throw();
};
}

#endif
