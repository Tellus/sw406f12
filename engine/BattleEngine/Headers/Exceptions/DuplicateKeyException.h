/*
 * DuplicateKeyException.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#pragma once

#include <exception>
#include <string>
 
namespace engine {
class DuplicateKeyException : public std::exception
{
public:
	std::string msg;

	DuplicateKeyException(std::string mess);
	~DuplicateKeyException() throw();
	virtual const char* what() const throw();
};
}