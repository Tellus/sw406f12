/*
 * FileError.h
 *
 *  Created on: 22/03/2012
 *      Author: Ezphares
 */

#ifndef FILEERROR_H_
#define FILEERROR_H_

enum file_err { FREAD, FWRITE };

class FileError {
public:
	file_err type;
	void *data;

	FileError(file_err type, void *data);
	virtual ~FileError();
};

#endif /* FILEERROR_H_ */
