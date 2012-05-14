/// compileerror.h
///
/// This file contains ...

#pragma once

#include <sstream>

namespace errors
{

class CompileError
{
public:
	CompileError(std::string type, std::string message, std::string file = "", int line = 0);
	virtual ~CompileError();

	std::string what();
	std::string where();

private:
	std::string _type;
	std::string _message;
	std::string _file;
	int _line;
};

} /* namespace errors */

