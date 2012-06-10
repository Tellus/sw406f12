#pragma once

#include "tokentypes.h"

#include <string>
#include <iostream>

namespace tokens
{

/**
 * Tokens are the basic output format of the scanner. This class acts as a
 * container for the token-related data during phase 1.
 **/
class Token
{
public:
    /**
     * Creates a new new Token instance.
     * \param type Particular type of token being created. See
     * Token/tokentypes.h for the list.
     * \param value 
     * \param file The file that the token was found in.
     * \param line Line number in file where the token was found.
     **/
	Token(FORMAT_TOKENTYPE type, std::string value, std::string file, unsigned int line);
	
	/**
	 * Destructor. Destroys the next token as well (so destroying the first
	 * token in the list should be a safe-all).
	 **/
	virtual ~Token();

    /**
     * Links another token to this one. This is our chaining mechanism to create
     * a linked list of tokens - a token stream.
     * \param next The next token in the list (this assumes that this token is the
     * last token in the list).
     * \return The token next - good for chaining.
     **/
	Token *append(Token *next);
	
	/**
	 * Pretty prints information about this token.
	 **/
	void print();

    /**
     * Type of token. See Token/tokentypes.h for a list.
     **/
	FORMAT_TOKENTYPE type;
	
	/**
	 * The value scanned as part of the token. Typically specific operators,
	 * declaration names, references, and such.
	 **/
	std::string value;
	
	/**
	 * Source file of this token. Particularly useful during multi-file
	 * compilation.
	 **/
	std::string file;
	
	/**
	 * Line numer where the token was found in its source file.
	 **/
	unsigned int line;
	
	/**
	 * The next token in the stream.
	 **/
	Token *next;

};

} /* namespace tokens */
