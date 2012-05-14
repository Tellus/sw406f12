/// compileerror.cpp
///
/// This file contains ...

#include "compileerror.h"

namespace errors
{

CompileError::CompileError(std::string type, std::string message, std::string file, int line) :
		_type(type),
		_message(message),
		_file(file),
		_line(line)
{ }

CompileError::~CompileError()
{
	// TODO Auto-generated destructor stub
}

std::string CompileError::what()
{
	std::stringstream s;
	s << "<" << this->_type << "> " << this->_message;
	return s.str();
}

std::string CompileError::where()
{
	std::stringstream s;
	s << "line " << this->_line << " in file \"" << this->_file << "\"";
	return s.str();
}

} /* namespace errors */
