/*
 * NullParameterException.cpp
 *
 *  Created on: 03/04/2012
 *      Author: Johannes
 */ 

#include "Exceptions/NullParameterException.h"
 
namespace engine {

NullParameterException::NullParameterException(std::string msg)
{
	this->msg = msg;
	this->what();
}

NullParameterException::~NullParameterException() throw()
{
    // Empty, though defined.
}

}
