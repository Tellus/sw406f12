/*
 * ParseError.h
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#ifndef PARSEERROR_H_
#define PARSEERROR_H_

#include <string>
#include "../Scanner/Token.h"

using namespace std;
using namespace lexer;

namespace parser {

class ParseError {
public:
	string expected;
	Token* token;

	ParseError(Token* token, string expected);
	virtual ~ParseError();
};

} /* namespace parser */
#endif /* PARSEERROR_H_ */
