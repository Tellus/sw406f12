#pragma once

#include "tokentypes.h"

#include <string>
#include <iostream>

namespace tokens
{

class Token
{
public:
	Token(FORMAT_TOKENTYPE type, std::string value, std::string file, unsigned int line);
	virtual ~Token();

	Token *append(Token *next);
	void print();

	FORMAT_TOKENTYPE type;
	std::string value;
	std::string file;
	unsigned int line;
	Token *next;

};

} /* namespace ez_thread */
