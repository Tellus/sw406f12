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
class NullParameterException : public BaseException
{
public:
	std::string msg;

	NullParameterException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~NullParameterException() throw();
};
}

#endif
