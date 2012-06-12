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

/**
 * Specific flags for our purposes. This one ignores newlines, and guarantees
 * that any new search starts from where the previous match was found. This
 * results in a convenient serial matching process - very good for scanning.
 **/
const boost::regex_constants::match_flag_type flags =
		boost::regex_constants::match_single_line
		| boost::regex_constants::match_continuous;

/**
 * Struct giving the details of a recent match.
 **/
typedef struct token_match
{
    /**
     * The token type matched. See tokentypes.h for a list.
     **/
	FORMAT_TOKENTYPE type;
	
	/**
	 * Number of lines that the match spans. I'm assuming we use this for
     * error reporting.
	 **/
	unsigned int lines;
	
	/**
	 * Contents of the match. For many token types (<=, >=, ==, the like), this
	 * is completely pointless. For others (variables, values), it's imperative.
	 **/
	std::string value;
} token_match;

/**
 * The RegexManager class wraps the somewhat tedious task of using regular
 * expressions with TR1 or Boost into a simpler form fit for our scanner.
 **/
class RegexManager
{
public:
    /**
     * Creates a new RegexManager instance. It calls initialize_regex to create
     * all the patterns we use (that is our syntax specification, yo).
     **/
	RegexManager();
	
	/**
	 * Cleans up.
	 **/
	virtual ~RegexManager();

    /**
     * Finds the next match in the input buffer. Remember, since we're only
     * scanning, we're only interested in tokens, not their grammer.
     * \param buffer The input buffer.
     * \return A match struct for the newly-found match. 
     **/
	token_match *match(std::string *buffer);
	
	/**
	 * Trims the current line of the input buffer. Currently, this simply means
	 * stripping it of whitespaces.
	 * \param buffer The input buffer to trim.
	 * \return The number of newlines trimmed off. I think.
	 **/
	unsigned int trim(std::string *buffer);

private:
    /**
     * Adds a pattern to our list of possible patterns.
     * \param key The tokentype that matches the pattern. We use this to
     * create a fitting token in the other end.
     * \param expression The pattern, in string format, to add.
     **/
	void add_regex(FORMAT_TOKENTYPE key, std::string expression);
	
	/**
	 * Initialises our entire syntax specification in regex form for Boost.
	 **/
	void initialize_regex();
	
	/**
	 * Counts the number of newlines in a string.
	 * \param str Input string.
	 * \return Number of newlines the string contains. Newlines are interpreted
	 * as '\n'.
	 **/
	unsigned int count_newlines(std::string str);

    /**
     * The regular expression for whitespaces. It is initialised in the
     * constructor.
     **/
	LPREGEX whitespace;
	
	/**
	 * Collection of valid patterns. This, gentlemen, is our run-time syntax
	 * specification.
	 **/
	std::map<REGEX_MAP_TYPE> expressions;
};

} /* namespace scanner */
