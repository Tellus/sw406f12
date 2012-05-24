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

/**
 * Exception thrown when you attempt to modify events during the raise sequence.
 * That would seriously muck up your willy.
 **/
class EventLockedException : public BaseException
{
public:
    /**
     * Creates a new instance with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	EventLockedException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~EventLockedException() throw();
};
}

#endif
