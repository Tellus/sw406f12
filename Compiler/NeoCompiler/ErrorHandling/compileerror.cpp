/// compileerror.cpp
///
/// This file contains ...

#include "compileerror.h"

namespace errors
{

CompileError::CompileError(std::string type, std::string message, std::string file, int line) :
		type(type),
		message(message),
		file(file),
		line(line)
{ }

CompileError::~CompileError()
{ }

std::string CompileError::what()
{
	std::stringstream s;
	s << "<" << this->type << "> " << this->message;
	return s.str();
}

std::string CompileError::where()
{
	std::stringstream s;

	if (this->line != 0)
		s << "line " << this->line << " in file ";

	s << "\"" << this->file << "\"";
	return s.str();
}

} /* namespace errors */
