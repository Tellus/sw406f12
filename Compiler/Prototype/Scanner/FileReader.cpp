/*
 * FileReader.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#include "FileReader.h"

using namespace std;

namespace lexer
{
    void FileReader::open()
    {
        if ((this->filestream.good() && this->filestream.is_open()) || this->filelist.size() == 0)
            return;

        this->filestream.close();
        this->filestream.open(this->filelist.front().c_str(), std::ios::in);

        if(!this->filestream.good())
            throw new FileError(FREAD, new string(this->filelist.front()));

        this->filelist.pop_front();
    }

    void FileReader::close()
    {
        this->filestream.close();
    }

    char FileReader::peek(unsigned int lookahead)
    {
        this->read();
        if (lookahead >= this->buffered)
        {
            return '\0';
        }

        return this->buffer[lookahead];
    }

    char* FileReader::devour(unsigned int length)
    {
        this->read();
        if (length > this->buffered)
        {
            length = this->buffered;
        }

        char* ret_arr = new char[length + 1];
        memcpy(ret_arr, this->buffer, length);
        ret_arr[length] = '\0';
        this->buffered -= length;
        memcpy(this->buffer, this->buffer+length, this->buffered);

        return ret_arr;
    }

    void FileReader::add_file(string filename)
    {
        this->filelist.push_back(filename);
    }

    void FileReader::read()
    {

        this->open();
        while (this->buffered < BUFFERSIZE && this->filestream.good())
        {
            if (this->filestream.good() && (int)(this->filestream.peek()) != -1)
            {
                this->filestream.get(this->buffer[this->buffered++]);
            }
            else
            {
                this->buffer[this->buffered++] = 0x1C; // File Seperator
                this->filestream.close();
                this->open();
            }
        }
    }

    FileReader::FileReader()
    {
        this->buffered = 0;
    }

    FileReader::~FileReader()
    {
    	this->close();
    }

}
