/*
 * DuplicateKeyException.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#ifndef BASEEXCEPTION_KEY_H_
#define BASEEXCEPTION_KEY_H_

#include <exception>
#include <string>
 
namespace engine {

/**
 * Exception typically used when someone attempts to add something to a map
 * where the key is already taken (for example, a second Health resource), and
 * will result in this exception.
 **/
class BaseException : public std::exception
{
public:
    /**
     * The message passed through with the exception itself. Should contain
     * a friendly, human-readable message along with the name of the disputed
     * key.
     **/
	std::string msg;

    BaseException();

    /**
     * Creates a new DuplicateKeyException with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	BaseException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~BaseException() throw();
};
}

#endif
