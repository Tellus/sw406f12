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
        int temp = BUFFERSIZE-this->buffered;
        while (this->filestream.good() && temp > 0)
            {
                this->filestream.read((this->buffer)+(this->buffered), temp);
                this->buffered += this->filestream.gcount();
                temp = BUFFERSIZE - this->buffered;

                if(!this->filestream.good())
                {
                    this->filestream.close();
                    if (this->filelist.empty())
                    {
                        return;
                    }
                    this->filestream.open(this->filelist.front().c_str(), std::ios::in);
                    this->filelist.pop_front();
                }
            }
    }

    FileReader::FileReader()
    {
        this->buffered = 0;
    }

    FileReader::~FileReader()
    {
        // TODO Auto-generated destructor stub
    }

}
