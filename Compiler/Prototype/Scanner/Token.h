/*
 * Token.h
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>
#include <iostream>

using namespace std;

namespace lexer
{
    enum token_type{$,
    			SEMICOLON, COMMA, DOT,
    			LBRACE, RBRACE, LBRACKET, RBRACKET, LPARAN, RPARAN,
    			IDENTIFIER, NUMBER, STRING, BOOL,
    			PLUS, MINUS, DIVIDE, MULTIPLY,
    			ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, DIVIDE_ASSIGN, MULTIPLY_ASSIGN,
    			EQUAL, NOTEQUAL, GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,
    			COMMENT,
    			MAKE, FROM,
    			REFERENCE_KEYWORD,
    			VALUE_KEYWORD
    	};

    class Token
    {
    public:
        token_type type;
        unsigned int line;
        unsigned int file;
        string contents;
        Token *next;

        /*Prints the token stream, starting from this token*/
        void purrdy_print(unsigned int indent = 0, bool newline = true);
        /*Append a token after this one, returns new token*/
        Token* append(Token *next);

        Token(unsigned int file, unsigned int line, token_type type, string contents);
        virtual ~Token();
    };
}

#endif /* TOKEN_H_ */
