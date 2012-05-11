/*
 * PrimarchDoesNotExistException.h
 *
 *  Created on: 04/05/2012
 *      Author: Johannes
 */ 

#ifndef PRIMARCH_DOES_NOT_EXIST_H_
#define PRIMARCH_DOES_NOT_EXIST_H_

#include <exception>
#include <string>
 
namespace engine {
class PrimarchDoesNotExistException : public std::exception
{
public:
	std::string msg;

	PrimarchDoesNotExistException();
	PrimarchDoesNotExistException(std::string mess);
	virtual ~PrimarchDoesNotExistException() throw();
	virtual const char* what() const throw();
};
}

#endif
