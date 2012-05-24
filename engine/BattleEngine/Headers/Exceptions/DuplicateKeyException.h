/*
 * DuplicateKeyException.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */ 

#ifndef DUPLICATE_KEY_H_
#define DUPLICATE_KEY_H_

#include "BaseException.h"
 
namespace engine {

/**
 * Exception typically used when someone attempts to add something to a map
 * where the key is already taken (for example, a second Health resource), and
 * will result in this exception.
 **/
class DuplicateKeyException : public BaseException
{
public:
    /**
     * Creates a new DuplicateKeyException with a specific message. For some
     * reason, the compiler errors out if you concatenate in the call.
     **/ 
	DuplicateKeyException(std::string mess);
	
	/**
	 * Destructor. Unimplemented, but necessary.
	 **/
	~DuplicateKeyException() throw();
};
}

#endif
