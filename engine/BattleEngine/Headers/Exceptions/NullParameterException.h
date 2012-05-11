/*
 * NullParameterException.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#ifndef NULL_PARAM_EXCEPTION_H_
#define NULL_PARAM_EXCEPTION_H_

#include <exception>
#include <string>
 
namespace engine {
class NullParameterException : public std::exception
{
public:
	std::string msg;

	NullParameterException(std::string mess);
	~NullParameterException() throw();
	virtual const char* what() const throw();
};
}

#endif
