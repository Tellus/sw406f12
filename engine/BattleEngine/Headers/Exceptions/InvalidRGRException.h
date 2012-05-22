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
class InvalidRGRException : public BaseException
{
public:
	InvalidRGRException(std::string mess);
	
    /**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~InvalidRGRException() throw();
};
}

#endif
