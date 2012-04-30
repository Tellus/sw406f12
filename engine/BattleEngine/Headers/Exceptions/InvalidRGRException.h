/*
 * InvalidRGRException.h
 *
 *  Created on: 2/04/2012
 *      Author: Johannes
 */ 

#include <exception>
#include <string>
 
namespace engine {
class InvalidRGRException : public std::exception
{
public:
	std::string msg;

	InvalidRGRException(std::string mess);
	~InvalidRGRException() throw();
	virtual const char* what() const throw();
};
}
