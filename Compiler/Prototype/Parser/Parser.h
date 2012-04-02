/*
 * Parser.h
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "ASTNode.h"
#include "../Scanner/Token.h"
#include "ParseError.h"

using namespace lexer;

namespace parser {

class Parser {
public:
	ASTNode *parse(Token *tokens);

	Parser();
	virtual ~Parser();

private:

	Token *start, *current;

	token_type input(unsigned int lookahead = 0);
	Token *advance(token_type type = ANY);

	ASTNode *accept_program();
	ASTNode *accept_declaration();
	ASTNode *accept_assingment_list();
	ASTNode *accept_assignment();
	ASTNode *accept_value();
	ASTNode *accept_set();
	ASTNode *accept_condition();
	ASTNode *accept_call();
	ASTNode *accept_expression();
	ASTNode *accept_term();
	ASTNode *accept_factor();
	ASTNode *accept_single_value();
	ASTNode *accept_class_member();
};

} /* namespace parser */
#endif /* PARSER_H_ */
