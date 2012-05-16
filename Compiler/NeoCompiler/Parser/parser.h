#pragma once

#include "../Token/token.h"
#include "../Trees/abstractsyntaxtree.h"
#include "../ErrorHandling/compileerror.h"

#include <sstream>

namespace parser
{

class Parser
{
public:
	Parser();
	virtual ~Parser();

	trees::AbstractSyntaxNode *parse(tokens::Token *stream);

private:
	tokens::Token *advance(FORMAT_TOKENTYPE type = tokens::TokentypeAny);
	FORMAT_TOKENTYPE input(std::size_t lookahead = 0);

	trees::AbstractSyntaxNode *accept_program();
	trees::AbstractSyntaxNode *accept_declaration();

	/* Deprecated */
	trees::AbstractSyntaxNode *accept_assingment_list();

	trees::AbstractSyntaxNode *accept_assignment();
	trees::AbstractSyntaxNode *accept_value();
	trees::AbstractSyntaxNode *accept_set();
	trees::AbstractSyntaxNode *accept_condition();
	trees::AbstractSyntaxNode *accept_call();
	trees::AbstractSyntaxNode *accept_expression();
	trees::AbstractSyntaxNode *accept_term();
	trees::AbstractSyntaxNode *accept_factor();
	trees::AbstractSyntaxNode *accept_single_value();
	trees::AbstractSyntaxNode *accept_class_member();

	tokens::Token *start, *current;
};

} /* namespace parser */
