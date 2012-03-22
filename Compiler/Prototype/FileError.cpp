/*
 * FileError.cpp
 *
 *  Created on: 22/03/2012
 *      Author: Ezphares
 */

#include "FileError.h"

#include <string>

using namespace std;

FileError::FileError(file_err type, void* data) {
	this->type = type;
	this->data = data;
}

FileError::~FileError() {
	switch (this->type)
	{
		case FREAD:
			delete (string*)(this->data);
			break;
		default:
			break;
	}
}

