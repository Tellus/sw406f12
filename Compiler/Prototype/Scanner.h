/*
 * Scanner.h
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "FileReader.h"
#include "Token.h"

using namespace std;

namespace lexer
{

    class Scanner
    {
    public:
        Token* scan();
        void add_file(string filename);

        Scanner();
        virtual ~Scanner();

    private:
        FileReader *filereader;
        Token *first;
        Token *last;
        unsigned int file, line;

        Token* make_token();
        Token* read_identifier();
        Token* read_number();
        Token* read_string(char delimiter);
        Token* read_comment(bool block);
        void generalize(char* c);
    };

}

#endif /* SCANNER_H_ */
