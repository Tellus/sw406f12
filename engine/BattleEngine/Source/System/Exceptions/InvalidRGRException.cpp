/*
 * InvalidRGRException.cpp
 *
 *  Created on: 26/04/2012
 *      Author: Johannes
 */ 

#include "Exceptions/InvalidRGRException.h"
 
namespace engine {

InvalidRGRException::InvalidRGRException(std::string msg)
{
	this->msg = msg;
	this->what();
}

InvalidRGRException::~InvalidRGRException() throw()
{}

const char* InvalidRGRException::what() const throw()
{
	return this->msg.c_str();
}

}
