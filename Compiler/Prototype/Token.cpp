/*
 * Token.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#include "Token.h"

using namespace std;

namespace lexer
{
    Token* Token::append(Token *next)
    {
        this->next = next;

        return next;
    }

    Token::Token(unsigned int file, unsigned int line, token_type type, string contents)
    {
        this->file = file;
        this->line = line;
        this->type = type;
        this->contents = contents;
        this->next = NULL;
    }

    Token::~Token()
    {
        delete next;
    }

}
