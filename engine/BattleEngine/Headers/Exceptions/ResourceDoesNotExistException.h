/*
 * ResourceDoesNotExistException.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */ 

#include <exception>
#include <string>
 
namespace engine {
class ResourceDoesNotExistException : public std::exception
{
public:
	std::string msg;

	ResourceDoesNotExistException(std::string mess);
	~ResourceDoesNotExistException() throw();
	virtual const char* what() const throw();
};
}
