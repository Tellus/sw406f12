/*
 * Scanner.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#include "Scanner.h"

namespace lexer
{

    Token* Scanner::scan()
    {
        while(this->filereader->peek() != '\0')
        {
            if(this->first == NULL)
                this->last = this->first = this->make_token();
            else
                this->last = this->last->append(this->make_token());
        }

        return this->first;
    }

    Token* Scanner::make_token()
    {
        char c = this->filereader->peek();

        while(c == ' ' || c == '\n' || c == '\t' || c == 0x1c)
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

        switch(c)
        {
            case ';':
                return new Token(this->file, this->line, SEMICOLON, this->filereader->devour());
            case 'a':

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
