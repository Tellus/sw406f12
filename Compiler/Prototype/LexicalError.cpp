/*
 * LexicalError.cpp
 *
 *  Created on: 22/03/2012
 *      Author: Ezphares
 */

#include "LexicalError.h"

namespace lexer {

LexicalError::LexicalError(unsigned int file, unsigned int line, lex_err type,
		void *data) {
	this->file = file;
	this->line = line;
	this->type = type;
	this->data = data;

}

LexicalError::~LexicalError() {
	switch (this->type)
	{
		case UNEXPECTEDSYMBOL:
			delete (char*)(this->type);
			break;

		default:
			break;
	}
}

} /* namespace lexer */
