/// compileerror.h
///
/// This file contains ...

#pragma once

#include <sstream>

namespace errors
{

/**
 * Your basic error. Thrown wherever the compiler hits an error.
 * For some reason, not an actual exception.
 * \todo Is there any continuous error facility or is it instant-off?
 **/
class CompileError
{
public:
    /**
     * Creates a new CompilerError instance.
     * \param type The type of error encountered.
     * \param message Human-readable description of the error.
     * \param file The file that the error occurred in.
     * \param line The line in file that the error occurred in.
     **/
	CompileError(std::string type, std::string message, std::string file = "", int line = 0);
	
	/**
	 * Destructor stub.
	 **/
	virtual ~CompileError();

    /**
     * Returns the type of error encountered.
     **/
	std::string what();
	
	/**
	 * Returns the location of the error in the source files.
	 **/
	std::string where();

    /**
     * Type of the error. Roughly equivalent to subclassing exceptions.
     **/
	std::string type;
	
	/**
	 * Human-readable message about the error.
	 **/
	std::string message;
	
	/**
	 * Filename of where the error occurred.
	 **/
	std::string file;
	
	/**
	 * Line number where the error occurred.
	 **/
	int line;
};

} /* namespace errors */

