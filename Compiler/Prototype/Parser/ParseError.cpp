/*
 * ParseError.cpp
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#include "ParseError.h"

namespace parser {

ParseError::ParseError(Token *token, string expected) {
	this->token = token;
	this->expected = expected;
}

ParseError::~ParseError() {
	// TODO Auto-generated destructor stub
}

} /* namespace parser */
