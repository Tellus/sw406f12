/*
 * Token.h
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#ifndef TOKEN_H_
#define TOKEN_H_
#include <string>

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

        void purrdy_print();
        Token* append(Token *next);

        Token(unsigned int file, unsigned int line, token_type type, string contents);
        virtual ~Token();
    };

}

#endif /* TOKEN_H_ */
