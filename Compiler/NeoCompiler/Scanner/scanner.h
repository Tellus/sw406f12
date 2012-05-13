#pragma once

#include "../Token/Token.h"
#include "regexmanager.h"

#include <string>
#include <list>
#include <iostream>
#include <fstream>

namespace scanner
{

class Scanner
{
public:
	Scanner();
	virtual ~Scanner();

	void add_file(std::string filename);
	tokens::Token *scan();

private:
	void open_file();
	tokens::Token *make_token();

	RegexManager *regex_manager;
	std::string buffer;
	std::list<std::string> files;
	unsigned int line;
	tokens::Token *first;
	tokens::Token *last;
};

} /* namespace scanner */
