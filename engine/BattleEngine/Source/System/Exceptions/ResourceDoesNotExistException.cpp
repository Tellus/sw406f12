/*
 * ResourceDoesNotExistException.cpp
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#include "Exceptions/ResourceDoesNotExistException.h"
 
namespace engine {

ResourceDoesNotExistException::ResourceDoesNotExistException(std::string msg)
{
	this->msg = msg;
	this->what();
}

ResourceDoesNotExistException::~ResourceDoesNotExistException() throw()
{
    // Empty, though defined.
}

const char* ResourceDoesNotExistException::what() const throw()
{
	return this->msg.c_str();
}

}
