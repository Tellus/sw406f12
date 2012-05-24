/*
 * EventLockedException.cpp
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */ 

#include "Exceptions/EventLockedException.h"
 
namespace engine {

EventLockedException::EventLockedException(std::string msg)
{
	this->msg = msg;
	this->what();
}

EventLockedException::~EventLockedException() throw()
{
	// I'm doing nothing!
}

}
