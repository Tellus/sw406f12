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

        FileReader *filereader;
        Token *first;
        Token *last;
        unsigned int file, line;

        Token* scan();
        Token* make_token();
        void add_file(string filename);

        void generalize(char* c);

        Scanner();
        virtual ~Scanner();
    };

}

#endif /* SCANNER_H_ */
