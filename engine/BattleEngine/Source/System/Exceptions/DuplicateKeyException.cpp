/*
 * DuplicateKeyException.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "Exceptions/DuplicateKeyException.h"
 
namespace engine {

DuplicateKeyException::DuplicateKeyException(std::string msg)
{
	this->msg = msg;
	this->what();
}

DuplicateKeyException::~DuplicateKeyException() throw()
{}

}
