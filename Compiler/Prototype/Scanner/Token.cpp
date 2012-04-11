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
    	string s_type = Token::stype(this->type);
    	unsigned int next_indent = indent;
    	bool next_newline = false;

    	if (this->type == SEMICOLON || this->type == LBRACE ||
    			this->type == RBRACE || this->type == COMMENT)
    		next_newline = true;

    	if (this->type == LBRACE)
    		next_indent++;

    	if (this->type == RBRACE)
			if (next_indent > 0)
			{
				next_indent--;
				indent--;
			}


    	if (newline)
    	{
    		cout << "\n";
			for (unsigned int i = 0; i < indent; i++)
				cout << "  ";
    	}

    	cout << s_type;

    	if (this->next != NULL)
    		this->next->purrdy_print(next_indent, next_newline);
    }

    string Token::stype(token_type type)
    {
    	string s_type;
    	switch (type)
    	{
    		case $:
    			s_type = "$ ";
    			break;
    		case COMMA:
    			s_type = ", ";
    			break;
    		case DOT:
    			s_type = ". ";
    			break;
    		case SEMICOLON:
    			s_type = "; ";
    			break;
    		case LBRACE:
    			s_type = "{ ";
    			break;
    		case RBRACE:
    			s_type = "} ";
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
    			s_type = "= ";
    			break;
    		case NOTEQUAL:
    			s_type = "!= ";
    			break;
    		case GREATER:
    			s_type = "> ";
    			break;
    		case GREATER_EQUAL:
    			s_type = ">= ";
    			break;
    		case LESS:
    			s_type = "< ";
    			break;
    		case LESS_EQUAL:
    			s_type = "<= ";
    			break;
    		case COMMENT:
    			s_type = "<comment> ";
    			break;
    		case FROM:
    			s_type = "\"from\" ";
    			break;
    		case MAKE:
    			s_type = "\"make\" ";
    			break;
    		case REFERENCE_KEYWORD:
    			s_type = "<reference> ";
    			break;
    		case VALUE_KEYWORD:
    			s_type = "<value> ";
    			break;

    		case ANY:
    			s_type = "";
    			break;
    	}

    	return s_type;
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
