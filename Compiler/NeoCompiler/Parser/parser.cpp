#include "parser.h"

namespace parser
{

Parser::Parser() :
		start(NULL),
		current(NULL)
{
}

Parser::~Parser()
{ }

trees::AbstractSyntaxNode *Parser::parse(tokens::Token *stream)
{
	this->start = this->current = stream;

	return this->accept_program();
}

tokens::Token *Parser::advance(FORMAT_TOKENTYPE type)
{
	tokens::Token *temp;
	if ((this->input() & type) == this->input())
	{
		temp = this->current;
		this->current = this->current->next;
		return temp;
	}
	else
	{
		throw "Parse Error: Unexpected token";
	}
}

FORMAT_TOKENTYPE Parser::input(std::size_t lookahead)
{
	tokens::Token *temp = this->current;

	for (std::size_t i = 0; i < lookahead; i++)
	{
		if (temp != NULL)
		{
			temp = temp->next;
		}
	}

	if (temp != NULL)
		return temp->type;

	return tokens::TokentypeNone;
}

trees::AbstractSyntaxNode *Parser::accept_program()
{
	trees::ProgramNode *node = new trees::ProgramNode();

	// Temporary solution for multiple files.
	while (this->input() != tokens::TokentypeNone)
	{
		while (this->input() == tokens::TokentypeMake)
		{
			node->add_child(this->accept_declaration());
		}
		this->advance(tokens::TokentypeEnd);
	}
	return node;
}

trees::AbstractSyntaxNode *Parser::accept_declaration()
{
	trees::DeclarationNode *node = new trees::DeclarationNode();

	this->advance(tokens::TokentypeMake);
	node->subclass = this->advance(tokens::TokentypeIdentifier)->value;
	this->advance(tokens::TokentypeFrom);
	node->superclass = this->advance(tokens::TokentypeIdentifier)->value;
	this->advance(tokens::TokentypeLBrace);

	while (this->input() == tokens::TokentypeIdentifier)
	{
		node->add_child(this->accept_assignment());
	}

	this->advance(tokens::TokentypeRBrace);

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_assignment()
{
	trees::AssignmentNode *node = new trees::AssignmentNode();

	node->identifier = this->advance(tokens::TokentypeIdentifier)->value;

	FORMAT_TOKENTYPE at = this->input();
	if (at != tokens::TokentypeAssign && at != tokens::TokentypePlusAssign &&
			at != tokens::TokentypeMinusAssign && at != tokens::TokentypeMultiplyAssign &&
			at != tokens::TokentypeDivideAssign)
	{ throw "Parse Error: Expected assignment type"; }
	node->assignment_type = this->advance()->value;

	node->add_child(this->accept_value());
	this->advance(tokens::TokentypeSemicolon);

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_value()
{
	if (this->input() == tokens::TokentypeLBracket)
		return this->accept_set();

	if (this->input() == tokens::TokentypeIdentifier &&
			this->input(1) == tokens::TokentypeLParan)
		return this->accept_call();

	return this->accept_condition();
}

trees::AbstractSyntaxNode *Parser::accept_set()
{
	trees::SetNode *node = new trees::SetNode();

	this->advance(tokens::TokentypeLBracket);

	if (this->input() != tokens::TokentypeRBracket)
	{
		node->add_child(this->accept_value());

		while (this->input() == tokens::TokentypeComma)
		{
			this->advance(tokens::TokentypeComma);
			node->add_child(this->accept_value());
		}
	}
	this->advance(tokens::TokentypeRBracket);

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_call()
{
	trees::CallNode *node = new trees::CallNode();

	node->identifier = this->advance(tokens::TokentypeIdentifier)->value;
	this->advance(tokens::TokentypeLParan);

	if (this->input() != tokens::TokentypeRParan)
	{
		node->add_child(this->accept_value());

		while (this->input() == tokens::TokentypeComma)
		{
			this->advance(tokens::TokentypeComma);
			node->add_child(this->accept_value());
		}
	}
	this->advance(tokens::TokentypeRParan);

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_condition()
{
	trees::ConditionNode *node = new trees::ConditionNode();

	trees::AbstractSyntaxNode *lhs = this->accept_expression();

	FORMAT_TOKENTYPE op = this->input();
	if (op != tokens::TokentypeEqual && op != tokens::TokentypeGreater &&
			op != tokens::TokentypeGreaterEqual && op != tokens::TokentypeLess &&
			op != tokens::TokentypeLessEqual && op != tokens::TokentypeNotEqual)
	{
		return lhs;
	}

	node->add_child(lhs);
	node->op = this->advance()->value;
	if (node->op == "=")
		node->op = "==";
	node->add_child(this->accept_expression());

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_expression()
{
	trees::ArithmeticNode *node = new trees::ArithmeticNode();

	trees::AbstractSyntaxNode *lhs = this->accept_term();

	FORMAT_TOKENTYPE op = this->input();
	if (op != tokens::TokentypePlus && op != tokens::TokentypeMinus)
	{
		return lhs;
	}

	node->add_child(lhs);
	node->op = this->advance()->value;
	node->add_child(this->accept_expression());

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_term()
{
	trees::ArithmeticNode *node = new trees::ArithmeticNode();

	trees::AbstractSyntaxNode *lhs = this->accept_factor();

	FORMAT_TOKENTYPE op = this->input();
	if (op != tokens::TokentypeMultiply && op != tokens::TokentypeDivide)
	{
		return lhs;
	}

	node->add_child(lhs);
	node->op = this->advance()->value;
	node->add_child(this->accept_term());

	return node;
}

trees::AbstractSyntaxNode *Parser::accept_factor()
{
	if (this->input() == tokens::TokentypeLParan)
	{
		trees::ArithmeticNode *node = new trees::ArithmeticNode();
		node->op = "()";

		this->advance(tokens::TokentypeLParan);
		node->add_child(this->accept_expression());
		this->advance(tokens::TokentypeRParan);
		return node;
	}

	return this->accept_single_value();
}

trees::AbstractSyntaxNode *Parser::accept_single_value()
{
	FORMAT_TOKENTYPE val = this->input();

	if (val == tokens::TokentypeNumber)
	{
		trees::NumberNode *node = new trees::NumberNode();
		node->raw = this->advance(tokens::TokentypeNumber)->value;
		// TODO: Parse
		return node;
	}

	if (val == tokens::TokentypeBool)
	{
		trees::BooleanNode *node = new trees::BooleanNode();
		node->raw = this->advance(tokens::TokentypeBool)->value;
		// TODO: Parse
		return node;
	}

	if (val == tokens::TokentypeString)
	{
		trees::StringNode *node = new trees::StringNode();
		node->value = node->raw = this->advance(tokens::TokentypeString)->value;
		node->value.erase(node->value.length() - 1, 1);
		node->value.erase(0, 1);
		return node;
	}

	if (val == tokens::TokentypeValue && this->input(1) != tokens::TokentypeDot)
	{
		trees::ValueKeyNode *node = new trees::ValueKeyNode();
		node->value = this->advance(tokens::TokentypeValue)->value;
		return node;
	}

	if (val == tokens::TokentypeIdentifier || val == tokens::TokentypeReference ||
			val == tokens::TokentypeValue)
	{
		return this->accept_class_member();
	}

	throw "Parse Error: Expected a valid value.";
}

trees::AbstractSyntaxNode *Parser::accept_class_member()
{
	trees::ClassMemberNode *node = new trees::ClassMemberNode();
	trees::AbstractSyntaxNode *temp;

	FORMAT_TOKENTYPE i = this->input();

	if (this->input() == tokens::TokentypeIdentifier)
	{
		temp = new trees::IdentifierNode(this->advance(tokens::TokentypeIdentifier)->value);
		node->add_child(temp);
	}
	else
	{
		temp = new trees::ReferenceKeyNode(this->advance(tokens::TokentypeReference | tokens::TokentypeValue)->value);
		node->add_child(temp);
	}

	i = this->input();
	while (i == tokens::TokentypeDot)
	{
		this->advance(tokens::TokentypeDot);
		temp = new trees::IdentifierNode(this->advance(tokens::TokentypeIdentifier)->value);
		node->add_child(temp);
		i = this->input();
	}

	return node;
}

} /* namespace parser */
