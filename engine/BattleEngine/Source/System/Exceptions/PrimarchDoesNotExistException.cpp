/*
 * ResourceDoesNotExistException.cpp
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#include "Exceptions/PrimarchDoesNotExistException.h"
 
namespace engine {

PrimarchDoesNotExistException::PrimarchDoesNotExistException(std::string msg)
{
	this->msg = msg;
}

PrimarchDoesNotExistException::~PrimarchDoesNotExistException() throw()
{
    // Empty, though defined.
}

}
