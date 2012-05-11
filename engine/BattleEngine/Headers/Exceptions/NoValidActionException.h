/*
 * NoValidActionException.h
 *
 *  Created on: 05/05/2012
 *      Author: Johannes
 */ 

#ifndef NO_VALID_ACTION_H_
#define NO_VALID_ACTION_H_

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

#endif
