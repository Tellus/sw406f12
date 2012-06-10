/// generator.h
///
/// This file contains ...

#pragma once

#include <map>
#include <list>
#include <string>
#include <fstream>

namespace codegen
{

/**
 * No clue what this does. Best guess? Function pointer.
 * \todo Figure out what this is.
 **/
typedef void(*Template)(std::fstream);

/**
 * Code Generator. Final phase of the compiler. Given that none of the
 * functionality is instance-bound, I'm wondering why this wasn't made as a
 * singleton.
 * Ah! It's actually kept in the independant function Gen(). The hell is this?
 **/
class Generator
{
public:
    /**
     * Constructor stub.
     **/ 
	Generator();
	
	/**
	 * Destructor stub.
	 **/
	virtual ~Generator();

    /**
     * Prints "// Add attributes..." to stream... WHY?!
     * \param stream The stream to print said sentence to.
     **/
	void character_template(std::fstream &stream);
	
	/**
	 * 
	 **/
	void character_post(std::fstream &stream, std::list<std::string> &assignments);
	
	/**
	 * Puts boilerplate code into stream based on the assignments passed.
	 * \param stream The stream to emit code to.
	 * \param assignments 
	 **/
	void ability_post(std::fstream &stream, std::list<std::string> &assignments);

private:
    /**
     * Checks a list to see if a specific item is contained in it.
     * \param list The list to run through.
     * \param item The value to check for.
     * \note Why doesn't this method use std::find_if to increase code reuse?
     **/
	bool list_contains(std::list<std::string> &list, std::string item);
};

Generator &Gen();

} /* namespace codegen */
