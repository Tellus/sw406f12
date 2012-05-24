/*
 * DuplicateKeyException.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#include "Exceptions/BaseException.h"
 
namespace engine {

BaseException::BaseException()
{
    this->msg = "Unspecified exception message.";
}

BaseException::BaseException(std::string msg)
{
	this->msg = msg;
	this->what();
}

BaseException::~BaseException() throw()
{}

}
