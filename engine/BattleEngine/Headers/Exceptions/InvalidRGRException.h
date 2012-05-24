/*
 * InvalidRGRException.h
 *
 *  Created on: 2/04/2012
 *      Author: Johannes
 */ 

#ifndef INVALID_RGR_EXCEPTION_H_
#define INVALID_RGR_EXCEPTION_H_

#include "BaseException.h"

namespace engine {

/**
 * Thrown in contexts where an unknown (or invalid) RGR is requested.
 * GameState will throw this if you try to use an unsupported RGR_Enum value.
 **/
class InvalidRGRException : public BaseException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	InvalidRGRException(std::string mess);
	
    /**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~InvalidRGRException() throw();
};
}

#endif
