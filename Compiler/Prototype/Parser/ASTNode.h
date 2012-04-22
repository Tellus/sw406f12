/*
 * ASTNode.h
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <list>
#include <string>
#include <iostream>

enum ast_type {NONE, NODE_PROG, NODE_DECLARATION,
	NODE_SUPERCLASS, NODE_SUBCLASS, NODE_ASSIGNMENT_LIST,
	NODE_ASSIGNMENT,
	NODE_IDENTIFIER, NODE_ASSIGN_TYPE, NODE_VALUE,
	NODE_SET, NODE_CONDITION, NODE_CALL,
	NODE_COMPARISON_TYPE, NODE_EXPRESSION, NODE_TERM, NODE_FACTOR,
	NODE_OPERATOR_ARITHMETIC,
	NODE_SINGLE_VALUE,
	NODE_NUMBER, NODE_STRING, NODE_BOOL, NODE_CLASS_MEMBER, NODE_VALUE_KEYWORD,
	NODE_REFERENCE_KEYWORD
};

enum primitive_type {T_NULL, T_STRING, T_NUMBER, T_BOOLEAN, T_LIST, T_PAIR, T_REFERENCE, T_CALL};

using namespace std;

namespace parser {

struct decoration
{
	primitive_type type;
	decoration* subtype;
};

class ASTNode {
public:
	list<ASTNode*> children;
	ast_type type;
	string data;
	decoration* dec;

	void add_child(ASTNode *child);
	void print_node(int indent = 0);
	string ntype(ast_type type);
	decoration* decorate();


	ASTNode(ast_type type, string data = "");
	virtual ~ASTNode();
};

} /* namespace parser */
#endif /* ASTNODE_H_ */
