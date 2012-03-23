/*
 * LexicalError.h
 *
 *  Created on: 22/03/2012
 *      Author: Ezphares
 */

#ifndef LEXICALERROR_H_
#define LEXICALERROR_H_

#include <iostream>

namespace lexer
{

	enum lex_err { UNEXPECTEDSYMBOL, UNCLOSEDSTRING, UNCLOSEDCOMMENT };

	class LexicalError
	{
	public:
		unsigned int file;
		unsigned int line;
		void *data;
		lex_err type;

		LexicalError(unsigned int file, unsigned int line, lex_err type,
				void *data);
		virtual ~LexicalError();
	};

} /* namespace lexer */
#endif /* LEXICALERROR_H_ */
