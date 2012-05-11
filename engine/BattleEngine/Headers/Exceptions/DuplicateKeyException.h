/*
 * DuplicateKeyException.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#ifndef DUPLICATE_KEY_H_
#define DUPLICATE_KEY_H_

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

#endif
