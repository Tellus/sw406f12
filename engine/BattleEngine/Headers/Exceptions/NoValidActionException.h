/*
 * NoValidActionException.h
 *
 *  Created on: 05/05/2012
 *      Author: Johannes
 */ 

#pragma once

#include <exception>
#include <string>
 
namespace engine {
class NoValidActionException : public std::exception
{
public:
	std::string msg;

	NoValidActionException(std::string mess);
	~NoValidActionException() throw();
	virtual const char* what() const throw();
};
}
