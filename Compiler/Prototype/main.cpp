/*
 * main.cpp
 *
 *  Created on: 19/03/2012
 *      Author: vixen
 */


#include <vector>
#include <string>
#include "Scanner/Scanner.h"
#include "Parser/Parser.h"

using namespace lexer;
using namespace std;
using namespace parser;

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
	catch (LexicalError *e)
	{
		cout << "<Syntax Error> ";

		switch (e->type)
		{
			case UNEXPECTEDSYMBOL:
				cout << "Unexpected symbol '" << *((char*)(e->data))
					 << "' in file <" << files[(e->file)] << "> on line "
					 << e->line << ".";
				break;

			case UNCLOSEDSTRING:
				cout << "Unclosed string in file <" << files[(e->file)]
				     << "> starting on line " << e->line << ".";
				break;

			case UNCLOSEDCOMMENT:
				cout << "Unclosed block comment in file <" << files[(e->file)]
				     << "> starting on line " << e->line << ".";
				break;
		}
		cout << endl;
		return 0;
	}
	catch (FileError *e)
	{
		switch (e->type)
		{
			case FREAD:
				cout << "Unable to open file <" << *((string*)(e->data)) << ">.";
				break;

			case FWRITE:
				break;
		}
		cout << endl;
		return 0;
	}

	cout << "Successfully scanned " << files.size() << " files." << endl << endl;
	tokens->purrdy_print();
	cout << endl;

	delete scanner;

	Parser *parser = new Parser();
	ASTNode *ast;

	try
	{
		ast = parser->parse(tokens);
	}
	catch (ParseError *e)
	{
		cout << "<Syntax Error> Received token " << Token::stype(e->token->type)
				<< "while parsing <" << files[e->token->file] << "> on line "
				<< e->token->line << ". Expected " << e->expected << ".";
		return 0;
	}

	cout << "Successfully parsed program." << endl << endl;

	delete parser;
	delete tokens;

	// TODO: Semantics

	delete ast;

	// TODO: Code gen

	return 0;
}
