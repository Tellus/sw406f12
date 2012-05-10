/*
 * Parser.cpp
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#include "Parser.h"

namespace parser {

ASTNode *Parser::parse(Token *tokens)
{
	this->start = this->current = tokens;

	return this->accept_program();
}

ASTNode *Parser::accept_program()
{
	ASTNode *node = new ASTNode(NODE_PROG);

	while (this->input() == MAKE)
		node->add_child(this->accept_declaration());


	if (this->input() != $)
		throw new ParseError(this->advance(), "\"make\" or end of file ");

	return node;
}

ASTNode *Parser::accept_declaration()
{
	ASTNode *node = new ASTNode(NODE_DECLARATION);

	this->advance(MAKE);
	node->add_child(new ASTNode(NODE_SUBCLASS, (this->advance(IDENTIFIER))->contents));
	this->advance(FROM);
	node->add_child(new ASTNode(NODE_SUPERCLASS, (this->advance(IDENTIFIER))->contents));
	this->advance(LBRACE);

	node->add_child(this->accept_assingment_list());

	this->advance(RBRACE);

	return node; //TODO
}

ASTNode *Parser::accept_assingment_list()
{
	ASTNode *node = new ASTNode(NODE_ASSIGNMENT_LIST);
	while (this->input() == IDENTIFIER)
		node->add_child(this->accept_assignment());

	return node;
}

ASTNode *Parser::accept_assignment()
{
	ASTNode *node = new ASTNode(NODE_ASSIGNMENT);

	node->add_child(new ASTNode(NODE_IDENTIFIER, (this->advance(IDENTIFIER))->contents));

	token_type assign_type = this->input();
	if (assign_type != ASSIGN && assign_type != DIVIDE_ASSIGN && assign_type != MULTIPLY_ASSIGN
			&& assign_type != PLUS_ASSIGN && assign_type != MINUS_ASSIGN)
		throw new ParseError(this->advance(), "assignment operator ");

	node->add_child(new ASTNode(NODE_ASSIGN_TYPE, (this->advance())->contents));

	node->add_child(this->accept_value());

	this->advance(SEMICOLON);
	return node;
}

ASTNode *Parser::accept_value()
{
	ASTNode *node = new ASTNode(NODE_VALUE);

	token_type t = this->input();

	if (t == LBRACKET)
		node->add_child(this->accept_set());
	else if (t == IDENTIFIER && this->input(1) == LPARAN) //LL(1)
		node->add_child(this->accept_call());
	else
		node->add_child(this->accept_condition());

	return node;
}

ASTNode *Parser::accept_set()
{
	this->advance(LBRACKET);

	ASTNode *node = new ASTNode(NODE_SET);

	if (this->input() != RBRACKET)
	{
		node->add_child(this->accept_value());

		while (this->input() == COMMA)
		{
			this->advance(COMMA);
			node->add_child(this->accept_value());
		}
	}
	this->advance(RBRACKET);

	return node;
}

ASTNode *Parser::accept_call()
{
	ASTNode *node = new ASTNode(NODE_CALL);

	node->add_child(new ASTNode(NODE_IDENTIFIER, (this->advance(IDENTIFIER))->contents));

	this->advance(LPARAN);

	if (this->input() != RPARAN)
	{
		node->add_child(this->accept_value());

		char c = this->input();
		while (c == COMMA)
		{
			this->advance(COMMA);
			node->add_child(this->accept_value());
			c = this->input();
		}
	}

	this->advance(RPARAN);

	return node;
}

ASTNode *Parser::accept_condition()
{
	ASTNode *node = new ASTNode(NODE_CONDITION);

	ASTNode *expr = this->accept_expression();

	token_type condition = this->input();
	if (condition != EQUAL && condition != NOTEQUAL && condition != GREATER
			&& condition != GREATER_EQUAL && condition != LESS && condition != LESS_EQUAL )
	{
		return expr; // Ascending expression to value
	}

	node->add_child(expr);
	node->add_child(new ASTNode(NODE_COMPARISON_TYPE, (this->advance())->contents));
	node->add_child(this->accept_expression());

	return node;
}

ASTNode *Parser::accept_expression()
{
	ASTNode *node = new ASTNode(NODE_EXPRESSION);

	node->add_child(this->accept_term());

	token_type op = this->input();

	while (op == PLUS || op == MINUS)
	{
		node->add_child(new ASTNode(NODE_OPERATOR_ARITHMETIC, (this->advance())->contents));
		node->add_child(this->accept_term());
		op = this->input();
	}

	return node;
}

ASTNode *Parser::accept_term()
{
	ASTNode *node = new ASTNode(NODE_TERM);

	node->add_child(this->accept_factor());

	token_type op = this->input();

	while (op == MULTIPLY || op == DIVIDE)
	{
		node->add_child(new ASTNode(NODE_OPERATOR_ARITHMETIC, (this->advance())->contents));
		node->add_child(this->accept_factor());
		op = this->input();
	}

	return node;
}

ASTNode *Parser::accept_factor()
{
	ASTNode *node = new ASTNode(NODE_FACTOR);

	if (this->input() == LPARAN)
	{
		this->advance(LPARAN);
		node->add_child(this->accept_expression());
		this->advance(RPARAN);
	}
	else
	{
		node->add_child(this->accept_single_value());
	}

	return node;
}

ASTNode *Parser::accept_single_value()
{
	// TODO: Should single-value be an intermediate node?

	if (this->input() == STRING)
		return new ASTNode(NODE_STRING, (this->advance())->contents);

	if (this->input() == BOOL)
		return new ASTNode(NODE_NUMBER, (this->advance())->contents);

	if (this->input() == NUMBER)
		return new ASTNode(NODE_BOOL, (this->advance())->contents);

	if (this->input() == VALUE_KEYWORD)
		return new ASTNode(NODE_VALUE_KEYWORD, (this->advance())->contents);

	if (this->input() == IDENTIFIER || this->input() == REFERENCE_KEYWORD)
		return this->accept_class_member();

	throw new ParseError(this->advance(), "value ");
}

ASTNode *Parser::accept_class_member()
{
	ASTNode *node = new ASTNode(NODE_CLASS_MEMBER);

	if (this->input() == IDENTIFIER)
		node->add_child(new ASTNode(NODE_IDENTIFIER, (this->advance())->contents));
	else
		node->add_child(new ASTNode(NODE_REFERENCE_KEYWORD, (this->advance())->contents));

	char c = this->input();

	while (c == DOT)
	{
		this->advance(DOT);
		node->add_child(new ASTNode(NODE_IDENTIFIER, (this->advance(IDENTIFIER))->contents));
		c = this->input();
	}

	return node;
}

Token *Parser::advance(token_type type)
{
	if (type == ANY || type == this->current->type)
	{
		Token *c = this->current;
		this->current = this->current->next;
		return c;
	}
	else
		throw new ParseError(this->current, Token::stype(type));
}

token_type Parser::input(unsigned int lookahead)
{
	Token *c = this->current;
	for (unsigned int i = 0; i < lookahead; i++)
		c = c->next;

	return c->type;
}

Parser::Parser() {

}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

} /* namespace parser */
