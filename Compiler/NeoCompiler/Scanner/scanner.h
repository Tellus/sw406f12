#pragma once

#include "../Token/token.h"
#include "regexmanager.h"

#include <string>
#include <list>
#include <iostream>
#include <fstream>

namespace scanner
{

/**
 * Phase 1 of our compiler, the scanner reads raw source code and converts it
 * to our tokens, ready to be passed to the parser.
 **/
class Scanner
{
public:
    /**
     * Creates a new Scanner instance, ready for use.
     **/
	Scanner();
	
	/**
	 * Scanner destructor. Destroys the regexmanager.
	 **/
	virtual ~Scanner();

    /**
     * Adds another file to the queue of files to be scanned.
     * \param filename Path to the file to be scanned.
     **/
	void add_file(std::string filename);
	
	/**
	 * Scans all the added files into a single token stream.
	 * \return The first token in the stream.
	 **/
	tokens::Token *scan();

private:
    /**
     * Adds the frontmost file to the file buffer.
     **/
	void open_file();
	
	/**
	 * Attempts to create the next token in the input stream.
	 * \return The newly-created token.
	 **/
	tokens::Token *make_token();

    /**
     * Regexmanager used to match tokens to the syntax.
     **/
	RegexManager *regex_manager;
	
	/**
	 * Input buffer of source code.
	 **/
	std::string buffer;
	
	/**
	 * List of files to be scanned.
	 **/
	std::list<std::string> files;
	
	/**
	 * Line in source file currently being scanned. Used mostly for error
	 * handling.
	 **/
	unsigned int line;
	
	/**
	 * First token in the stream.
	 **/
	tokens::Token *first;
	
	/**
	 * Last token in the stream.
	 **/
	tokens::Token *last;
};

} /* namespace scanner */
