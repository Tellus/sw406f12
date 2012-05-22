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
 * Generic Engine exception. Should be considered abstract since using it
 * is terribly unhelpful.
 **/
class BaseException : public std::exception
{
public:
    /**
     * The message passed through with the exception itself. Should contain
     * a friendly, human-readable message.
     **/
	std::string msg;

    /**
     * Constructs a BaseException with a very unhelpful error message.
     **/
    BaseException();

    /**
     * Creates a new instance with a specific message. For some
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
