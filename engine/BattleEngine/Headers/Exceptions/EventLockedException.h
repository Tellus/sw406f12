/*
 * EventLockedException.h
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */ 

#pragma once

#include <exception>
#include <string>
 
namespace engine {
class EventLockedException : public std::exception
{
public:
	std::string msg;

	EventLockedException(std::string mess);
	~EventLockedException() throw();
	virtual const char* what() const throw();
};
}