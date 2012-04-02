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

using namespace std;

namespace parser {

class ASTNode {
public:
	list<ASTNode*> children;
	ast_type type;
	string data;

	void add_child(ASTNode *child);

	ASTNode(ast_type type, string data = "");
	virtual ~ASTNode();
};

} /* namespace parser */
#endif /* ASTNODE_H_ */
