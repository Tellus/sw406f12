/*
 * FileReader.h
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_
#define BUFFERSIZE 512
#define CHUNKSIZE BUFFERSIZE / 2

#include <fstream>
#include <list>
#include <string>
#include <cstring>
#include "FileError.h"

using namespace std;

namespace lexer
{

    class FileReader
    {
    public:
    	/*Returns the character which is 'lookahead' characters from the first in the buffer. Does not advance stream*/
        char peek(unsigned int lookahead = 0);
        /*Returns the first 'length' characters from the buffer, and advances the stream*/
        char* devour(unsigned int length = 1);
        /*Adds a file to be read*/
        void add_file(string filename);

        FileReader();
        virtual ~FileReader();

    private:
        ifstream filestream;
        list<string> filelist;
        char buffer[BUFFERSIZE];
        unsigned int buffered;

        void open();
        void close();
        void read();
    };

}

#endif /* FILEREADER_H_ */
