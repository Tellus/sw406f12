/*
 * EventLockedException.h
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */ 

#ifndef EVENT_LOCKED_EXCEPTION_H_
#define EVENT_LOCKED_EXCEPTION_H_

#include "BaseException.h"
 
namespace engine {
class EventLockedException : public BaseException
{
public:
	EventLockedException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~EventLockedException() throw();
};
}

#endif
