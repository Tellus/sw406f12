/*
 * ResourceDoesNotExistException.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#pragma once

#include <exception>
#include <string>

#include "PrimarchDoesNotExistException.h"

namespace engine {
class ResourceDoesNotExistException : public PrimarchDoesNotExistException
{
public:
	ResourceDoesNotExistException(std::string mess);
	virtual ~ResourceDoesNotExistException() throw();
	virtual const char* what() const throw();
};
}
