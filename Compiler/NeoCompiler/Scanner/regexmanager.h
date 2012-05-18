#pragma once

#include "../Token/tokentypes.h"
#include "../ErrorHandling/compileerror.h"

#include <boost/regex.hpp>
#include <map>
#include <string>

#define REGEX boost::regex
#define LPREGEX REGEX*
#define REGEX_MAP_TYPE FORMAT_TOKENTYPE, LPREGEX

namespace scanner
{

const boost::regex_constants::match_flag_type flags =
		boost::regex_constants::match_single_line
		| boost::regex_constants::match_continuous;

typedef struct token_match
{
	FORMAT_TOKENTYPE type;
	unsigned int lines;
	std::string value;
} token_match;

class RegexManager
{
public:
	RegexManager();
	virtual ~RegexManager();

	token_match *match(std::string *buffer);
	unsigned int trim(std::string *buffer);

private:
	void add_regex(FORMAT_TOKENTYPE key, std::string expression);
	void initialize_regex();
	unsigned int count_newlines(std::string str);

	LPREGEX whitespace;
	std::map<REGEX_MAP_TYPE> expressions;
};

} /* namespace scanner */
