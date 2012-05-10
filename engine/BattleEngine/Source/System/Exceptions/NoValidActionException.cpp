/*
 * InvalidRGRException.cpp
 *
 *  Created on: 05/05/2012
 *      Author: Johannes
 */ 

#include "Exceptions/NoValidActionException.h"
 
namespace engine {

NoValidActionException::NoValidActionException(std::string msg)
{
	this->msg = msg;
	this->what();
}

NoValidActionException::~NoValidActionException() throw()
{
    // Empty, though defined.
}

const char* NoValidActionException::what() const throw()
{
	return this->msg.c_str();
}

}
