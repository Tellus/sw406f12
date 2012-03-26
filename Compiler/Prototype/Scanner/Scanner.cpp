/*
 * Scanner.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#include "Scanner.h"

using namespace std;

namespace lexer
{

    Token* Scanner::scan()
    {
        do
        {
            if(this->first == NULL)
                this->last = this->first = this->make_token();
            else
                this->last = this->last->append(this->make_token());
        }
        while (this->last->type != $);

        return this->first;
    }

    Token* Scanner::make_token()
    {
        char nc, c = this->filereader->peek();
        int l;

        while(c == ' ' || c == '\n' || c == '\t' || c == 0x1C)
        {
            this->filereader->devour();

            if(c == '\n')
                this->line++;
            if(c == 0x1c)
            {
                this->file++;
                this->line = 1;
            }

            c = this->filereader->peek();
        }

        if (c == '\0')
        {
        	return new Token(this->file, this->line, $, "");
        }

        this->generalize(&c);

        switch(c)
        {
            case ';':
                return new Token(this->file, this->line, SEMICOLON, this->filereader->devour());

            case ',':
                return new Token(this->file, this->line, COMMA, this->filereader->devour());

            case '.':
                return new Token(this->file, this->line, DOT, this->filereader->devour());

            case '{':
                return new Token(this->file, this->line, LBRACE, this->filereader->devour());

            case '}':
                return new Token(this->file, this->line, RBRACE, this->filereader->devour());

            case '[':
                return new Token(this->file, this->line, LBRACKET, this->filereader->devour());

            case ']':
                return new Token(this->file, this->line, RBRACKET, this->filereader->devour());

            case '(':
                return new Token(this->file, this->line, LPARAN, this->filereader->devour());

            case ')':
                return new Token(this->file, this->line, RPARAN, this->filereader->devour());

            case '_':
            case 'a':
            	return this->read_identifier();

            case '1':
            	return this->read_number();

            case '-':
            	nc = this->filereader->peek(1);
            	this->generalize(&nc);
            	if (nc == '1')
            		return this->read_number();

            	if (nc == ':')
            		return new Token(this->file, this->line, MINUS_ASSIGN, this->filereader->devour(2));

            	return new Token(this->file, this->line, MINUS, this->filereader->devour());

            case '"':
            case 0x27:
            	return this->read_string(c);

            case '+':
            	nc = this->filereader->peek(1);
            	if (nc == ':')
            		return new Token(this->file, this->line, PLUS_ASSIGN, this->filereader->devour(2));

            	return new Token(this->file, this->line, PLUS, this->filereader->devour());

            case '*':
            	nc = this->filereader->peek(1);
            	if (nc == ':')
            		return new Token(this->file, this->line, MULTIPLY_ASSIGN, this->filereader->devour(2));

            	return new Token(this->file, this->line, MULTIPLY, this->filereader->devour());

            case '/':
            	nc = this->filereader->peek(1);

            	if (nc == '/')
            		return this->read_comment(false);

            	if (nc == '*')
            		return this->read_comment(true);

            	if (nc == ':')
            		return new Token(this->file, this->line, DIVIDE_ASSIGN, this->filereader->devour(2));

            	return new Token(this->file, this->line, DIVIDE, this->filereader->devour());

            case ':':
                return new Token(this->file, this->line, ASSIGN, this->filereader->devour());

            case '=':
            	nc = this->filereader->peek(1);
            	if (nc == '=')
            		l = 2;
            	else
            		l = 1;
            	return new Token(this->file, this->line, EQUAL, this->filereader->devour(l));

            case '!':
				nc = this->filereader->peek(1);
				if (nc == '=')
					return new Token(this->file, this->line, NOTEQUAL, this->filereader->devour(2));

				throw new LexicalError(this->file, this->line, UNEXPECTEDSYMBOL,
						new char(c));

            case '<':
            	nc = this->filereader->peek(1);
            	if (nc == '=')
            		return new Token(this->file, this->line, LESS_EQUAL, this->filereader->devour(2));

            	return new Token(this->file, this->line, LESS, this->filereader->devour());

            case '>':
            	nc = this->filereader->peek(1);
            	if (nc == '=')
            		return new Token(this->file, this->line, GREATER_EQUAL, this->filereader->devour(2));

            	return new Token(this->file, this->line, GREATER, this->filereader->devour());

            default:
            	throw new LexicalError(this->file, this->line, UNEXPECTEDSYMBOL,
            			new char(c));
        }
    }

    void Scanner::add_file(string filename)
    {
        this->filereader->add_file(filename);
    }

    void Scanner::generalize(char* c)
    {
        if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
            *c = 'a';

        if (*c >= '0' && *c <= '9')
            *c = '1';
    }

    Token *Scanner::read_identifier()
    {
    	char c = 'a';
    	int i = 0;
    	string id = "";

    	while (c == 'a' || c == '1' || c == '_')
    	{
    		c = this->filereader->peek(++i);
    		this->generalize(&c);
    		if (i >= CHUNKSIZE)
    		{
    			id += this->filereader->devour(i);
    			i = 0;
    		}
    	}

    	id += this->filereader->devour(i);

    	if (id == "true" || id == "false")
    		return new Token(this->file, this->line, BOOL, id);

    	if (id == "make")
    		return new Token(this->file, this->line, MAKE, id);

    	if (id == "from")
    		return new Token(this->file, this->line, FROM, id);

    	if (id == "this" || id == "owner")
    		return new Token(this->file, this->line, REFERENCE_KEYWORD, id);

    	if (id == "self" || id == "enemy" || id == "ally" || id == "team_enemy" ||
    			id == "team_ally" || id == "all")
    		return new Token(this->file, this->line, VALUE_KEYWORD, id);

    	return new Token(this->file, this->line, IDENTIFIER, id);
    }

    Token *Scanner::read_number()
    {
    	char c = this->filereader->peek();
    	int i = 0;
    	string id;

    	if (c == '-')
    		c = this->filereader->peek(++i);
    	this->generalize(&c);

    	while (c == '1')
    	{
    		c = this->filereader->peek(++i);
    		this->generalize(&c);
    	}

    	if (c == '.')
    	{
    		c = this->filereader->peek(++i);
    		this->generalize(&c);
    		if (c != '1')
    		{
    			throw new LexicalError(this->file, this->line, UNEXPECTEDSYMBOL,
						new char(c));
    		}
    		while (c == '1')
    		{
    			c = this->filereader->peek(++i);
    			this->generalize(&c);
    		}
    	}

    	id += this->filereader->devour(i);

    	if (c == 'a')
    	{
    		throw new LexicalError(this->file, this->line, UNEXPECTEDSYMBOL,
					new char(c));
    	}

    	return new Token(this->file, this->line, NUMBER, id);
    }

    Token *Scanner::read_string(char delimiter)
    {
    	char c = ' ';
    	int i = 0;
    	unsigned int start = this->line;
    	string id;

    	while (c != delimiter)
    	{
    		c = this->filereader->peek(++i);

    		if (c == '\0' || c == 0x1C)
    			throw new LexicalError(this->file, start, UNCLOSEDSTRING, NULL);

    		if (c == '\n')
    			this->line++;

    		if (i >= CHUNKSIZE)
    		{
    			id += this->filereader->devour(i);
    			i = 0;
    		}
    	}

    	id += this->filereader->devour(i + 1);

    	return new Token(this->file, this->line, STRING, id);
    }

    Token *Scanner::read_comment(bool block)
    {
    	char c = ' ';
    	int i = 0;
    	unsigned int start = this->line;
    	string id;

    	while (true)
    	{
    		c = this->filereader->peek(++i);

    		if ((c == '\0' || c == 0x1C) && block)
    			throw new LexicalError(this->file, start, UNCLOSEDCOMMENT, NULL);

    		if (c == '\n')
    		{
    			if (block)
    				this->line++;
    			else
    				break;
    		}

    		if (c == '*' && block)
    		{
    			if (this->filereader->peek(i + 1) == '/')
    			{
    				i += 2;
    				break;
    			}
    		}

    		if (i >= CHUNKSIZE)
    		{
    			id += this->filereader->devour(i);
    			i = 0;
    		}
    	}

    	id += this->filereader->devour(i);

    	return new Token(this->file, this->line, COMMENT, id);
    }

    Scanner::Scanner()
    {
        this->filereader = new FileReader();
        this->first = NULL;
        this->last = NULL;
        this->file = 0;
        this->line = 1;
    }

    Scanner::~Scanner()
    {
        delete this->filereader;
    }

}
