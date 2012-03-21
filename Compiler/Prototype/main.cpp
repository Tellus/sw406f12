/*
 * main.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */

#include <vector>
#include <string>
#include "Scanner.h"

using namespace lexer;
using namespace std;

int main (int argc, char* argv[])
{
	vector<string> files;
	Scanner *scanner = new Scanner();

	for (int i = 1; i < argc; i++)
	{
		scanner->add_file(argv[i]);
		files.push_back(argv[i]);
	}

	Token *tokens;

	try
	{
		tokens = scanner->scan();
	}
	catch (char* error)
	{
	}

	delete scanner;
	delete tokens;

	return 0;
}
