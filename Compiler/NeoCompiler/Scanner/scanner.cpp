#include "scanner.h"

namespace scanner
{

Scanner::Scanner()
{
	this->regex_manager = new RegexManager();
}

Scanner::~Scanner()
{
	delete this->regex_manager;
}

void Scanner::add_file(std::string filename)
{
	this->files.push_back(filename);
}

tokens::Token *Scanner::scan()
{
	this->first = this->last = NULL;
	this->buffer = "";

	while (this->files.size() > 0)
	{
		if (this->buffer.length() == 0)
		{
			this->open_file();
		}

		tokens::Token* temp = this->make_token();
		if (temp->type == tokens::TokentypeComment) { continue; }
		if (temp->type == tokens::TokentypeEnd) { this->files.pop_front(); }

		if (this->first == NULL)
		{
			this->first = this->last = temp;
		}
		else
		{
			this->last = this->last->append(temp);
		}

	}

	return this->first;
}

void Scanner::open_file()
{
	this->line = 1;
	std::ifstream stream(this->files.front().c_str());
	stream.unsetf(std::ios::skipws); // We want to preserve whitespace here, to seperate identifiers
	if (!stream.good())
		throw "I/O error";
	this->buffer = std::string((std::istream_iterator<char>(stream)),
			std::istream_iterator<char>());
	stream.close();

	std::cout << "File open" << std::endl;
}

tokens::Token *Scanner::make_token()
{
	/*std::cout << "Trimming whitespace " << this->line;*/
	this->line += this->regex_manager->trim(&this->buffer);
	/*std::cout << " - " << this->line << std::endl;*/

	tokens::Token *ret;

	token_match *temp = this->regex_manager->match(&this->buffer);
	if (temp != NULL)
	{
		ret = new tokens::Token(temp->type, temp->value, this->files.front(), this->line);
		this->line += temp->lines;
		delete temp;
	}
	else
	{
		throw "Syntax Error!";
	}

	return ret;
}

} /* namespace scanner */
