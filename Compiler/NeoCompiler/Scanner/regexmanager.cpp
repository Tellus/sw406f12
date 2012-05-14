#include "regexmanager.h"

namespace scanner
{

RegexManager::RegexManager()
{
	this->initialize_regex();

	this->whitespace = new REGEX("^\\s*");
}

RegexManager::~RegexManager()
{
	delete this->whitespace;
	for (std::map<REGEX_MAP_TYPE>::iterator it = this->expressions.begin();
				it != this->expressions.end(); it++) {
		delete (*it).second;
	}
}

token_match *RegexManager::match(std::string *buffer)
{
	boost::smatch match;
	token_match *ret = NULL;

	for (std::map<REGEX_MAP_TYPE>::iterator it = this->expressions.begin();
			it != this->expressions.end(); it++) {
		if (boost::regex_search((*buffer), match, *(*it).second, flags))
		{
			if (!match[0].matched)
				continue;
			if (ret != NULL)
			{
				if ((unsigned int)match[0].length() > ret->value.length())
				{
					delete ret;
				}
				else { continue; }
			}
			ret = new token_match;
			ret->type = (*it).first;
			ret->value = match[0];
			ret->lines = this->count_newlines(match[0]);
		}
	}
	if (ret == NULL)
	{
		throw "Syntax Error";
	}

	buffer->erase(0, ret->value.length());
	return ret;
}

unsigned int RegexManager::trim(std::string *buffer)
{
	boost::smatch match;
	int lines = 0;

	if (boost::regex_search((*buffer), match, *this->whitespace, flags))
	{
		lines = this->count_newlines(match[0]);
		buffer->erase(0, match[0].length());
	}

	return lines;
}

void RegexManager::add_regex(FORMAT_TOKENTYPE key, std::string expression)
{
	LPREGEX temp = new REGEX(expression);

	std::pair<REGEX_MAP_TYPE> pair(key, temp);

	this->expressions.insert(pair);
}

void RegexManager::initialize_regex()
{
	this->add_regex(tokens::TokentypeEnd, "^$");

	this->add_regex(tokens::TokentypeSemicolon, "^;");
	this->add_regex(tokens::TokentypeComma, "^,");
	this->add_regex(tokens::TokentypeDot, "^\\.");

	this->add_regex(tokens::TokentypeLBrace, "^\\{");
	this->add_regex(tokens::TokentypeRBrace, "^\\}");
	this->add_regex(tokens::TokentypeLBracket, "^\\[");
	this->add_regex(tokens::TokentypeRBracket, "^\\]");
	this->add_regex(tokens::TokentypeLParan, "^\\(");
	this->add_regex(tokens::TokentypeRParan, "^\\)");

	this->add_regex(tokens::TokentypeNumber, "^-?\\d+(\\.\\d+)?");
	this->add_regex(tokens::TokentypeString, "(^\"[^\"]*\")|(^'[^']*')");
	this->add_regex(tokens::TokentypeBool, "(^true)|(^false)");

	this->add_regex(tokens::TokentypeAssign, "^:");
	this->add_regex(tokens::TokentypePlusAssign, "^\\+:");
	this->add_regex(tokens::TokentypeMinusAssign, "^-:");
	this->add_regex(tokens::TokentypeMultiplyAssign, "^\\*:");
	this->add_regex(tokens::TokentypeDivideAssign, "^/:");

	this->add_regex(tokens::TokentypePlus, "^\\+");
	this->add_regex(tokens::TokentypeMinus, "^-");
	this->add_regex(tokens::TokentypeMultiply, "^\\*");
	this->add_regex(tokens::TokentypeDivide, "^/");

	this->add_regex(tokens::TokentypeEqual, "^==?");
	this->add_regex(tokens::TokentypeEqual, "^!=?");
	this->add_regex(tokens::TokentypeGreater, "^>");
	this->add_regex(tokens::TokentypeGreaterEqual, "^>=");
	this->add_regex(tokens::TokentypeLess, "^<");
	this->add_regex(tokens::TokentypeLessEqual, "^<=");

	this->add_regex(tokens::TokentypeComment, "^(//.*?\\n)|(/\\*.*?\\*/)");

	this->add_regex(tokens::TokentypeIdentifier, "^\\w[\\w\\d]*");
	this->add_regex(tokens::TokentypeMake, "^make");
	this->add_regex(tokens::TokentypeFrom, "^from");
	this->add_regex(tokens::TokentypeReference, "(^owner)|(^this)");
	this->add_regex(tokens::TokentypeValue, "(^self)|(^enemy)|(^ally)|(^team_enemy)|(^team_ally)|(^all)");
}

unsigned int RegexManager::count_newlines(std::string str)
{
	unsigned int count = 0;
	int n = str.length();

	for (int i = 0; i < n; i++) {
		if (str[i] == '\n')
		{
			count++;
		}
	}

	return count;
}
} /* namespace scanner */
