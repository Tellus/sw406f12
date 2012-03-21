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

using namespace std;

namespace lexer
{

    class FileReader
    {
    public:
        char peek(unsigned int lookahead = 0);
        /*This reads the first characters from the buffer*/
        char* devour(unsigned int length = 1);
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
