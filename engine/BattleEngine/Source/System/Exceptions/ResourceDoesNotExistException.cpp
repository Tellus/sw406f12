/*
 * ResourceDoesNotExistException.cpp
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#include "Exceptions/ResourceDoesNotExistException.h"
 
namespace engine {

ResourceDoesNotExistException::ResourceDoesNotExistException(std::string msg) :
    PrimarchDoesNotExistException(msg)
{}

ResourceDoesNotExistException::~ResourceDoesNotExistException() throw()
{
    // Empty, though defined.
}

}
