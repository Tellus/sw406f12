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

    void Token::purrdy_print(unsigned int indent, bool newline)
    {
    	string s_type;
    	unsigned int next_indent = indent;
    	bool next_newline = false;

    	switch (this->type)
    	{
    		case $:
    			s_type = "$\n";
    			break;
    		case COMMA:
    			s_type = ", ";
    			break;
    		case DOT:
    			s_type = ". ";
    			break;
    		case SEMICOLON:
    			s_type = ";\n";
    			next_newline = true;
    			break;
    		case LBRACE:
    			s_type = "\n{\n";
    			next_indent++;
    			next_newline = true;
    			break;
    		case RBRACE:
    			s_type = "}\n";
    			if (next_indent > 0)
    			{
    				next_indent--;
    				indent--;
    			}
    			next_newline = true;
    			break;
    		case LBRACKET:
    			s_type = "[ ";
    			break;
    		case RBRACKET:
    			s_type = "] ";
    			break;
    		case LPARAN:
    			s_type = "( ";
    			break;
    		case RPARAN:
    			s_type = ") ";
    			break;
    		case IDENTIFIER:
    			s_type = "<identifier> ";
    			break;
    		case NUMBER:
    			s_type = "<number> ";
    			break;
    		case STRING:
    			s_type = "<string> ";
    			break;
    		case BOOL:
    			s_type = "<bool> ";
    			break;
    		case PLUS:
    			s_type = "+ ";
    			break;
    		case MINUS:
    			s_type = "- ";
    			break;
    		case DIVIDE:
    			s_type = "/ ";
    			break;
    		case MULTIPLY:
    			s_type = "* ";
    			break;
    		case ASSIGN:
    			s_type = ": ";
    			break;
    		case PLUS_ASSIGN:
    			s_type = "+: ";
    			break;
    		case MINUS_ASSIGN:
    			s_type = "-: ";
    			break;
    		case DIVIDE_ASSIGN:
    			s_type = "/: ";
    			break;
    		case MULTIPLY_ASSIGN:
    			s_type = "*: ";
    			break;
    		case EQUAL:
    			s_type = "=";
    			break;
    		case NOTEQUAL:
    			s_type = "!=";
    			break;
    		case GREATER:
    			s_type = ">";
    			break;
    		case GREATER_EQUAL:
    			s_type = ">=";
    			break;
    		case LESS:
    			s_type = "<";
    			break;
    		case LESS_EQUAL:
    			s_type = "<=";
    			break;
    		case COMMENT:
    			s_type = "<comment> ";
    			break;
    		case FROM:
    			s_type = "from ";
    			break;
    		case MAKE:
    			s_type = "make ";
    			break;
    		case REFERENCE_KEYWORD:
    			s_type = "<reference> ";
    			break;
    		case VALUE_KEYWORD:
    			s_type = "<value> ";
    			break;
    	}

    	if (newline)
			for (unsigned int i = 0; i < indent; i++)
				cout << "  ";

    	cout << s_type;

    	if (this->next != NULL)
    		this->next->purrdy_print(next_indent, next_newline);
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