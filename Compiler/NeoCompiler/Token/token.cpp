#include "token.h"

namespace tokens
{

Token::Token(FORMAT_TOKENTYPE type, std::string value, std::string file, unsigned int line)
{
	this->type = type;
	this->value = value;
	this->file = file;
	this->line = line;
	this->next = NULL;
}

Token::~Token()
{
	delete this->next;
}

Token *Token::append(Token *next)
{
	this->next = next;
	return next;
}

void Token::print()
{
	std::cout << this->line << ": " << this->type << " " << this->value << std::endl;

	if (this->next != NULL)
	{
		next->print();
	}
}

} /* namespace tokens */
