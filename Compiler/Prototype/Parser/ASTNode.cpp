/*
 * ASTNode.cpp
 *
 *  Created on: 25/03/2012
 *      Author: Ezphares
 */

#include "ASTNode.h"

namespace parser {

void ASTNode::add_child(ASTNode *child)
{
	this->children.push_back(child);
	this->dec = NULL;
}

void ASTNode::print_node(int indent)
{
	for (int i = 0; i < indent; i++)
	{
		cout << "  ";
	}

	string node_type = ASTNode::ntype(this->type);

	cout << "Type: " << node_type.c_str() << ", Data: " << this->data.c_str() << "\n";
	for (list<ASTNode*>::iterator i = this->children.begin(); i != this->children.end(); i++)
	{
		(*i)->print_node(indent+1);
	}
}

string ASTNode::ntype(ast_type type)
{
	string t_type;
	switch (type)
	{
		case NONE:
			t_type = "No Type";
			break;
		case NODE_PROG:
			t_type = "Program";
			break;
		case NODE_DECLARATION:
			t_type = "Declaration";
			break;
		case NODE_SUPERCLASS:
			t_type = "Superclass";
			break;
		case NODE_SUBCLASS:
			t_type = "Subclass";
			break;
		case NODE_ASSIGNMENT_LIST:
			t_type = "Assignment List";
			break;
		case NODE_ASSIGNMENT:
			t_type = "Assignment";
			break;
		case NODE_IDENTIFIER:
			t_type = "Identifier";
			break;
		case NODE_ASSIGN_TYPE:
			t_type = "Assign Type";
			break;
		case NODE_VALUE:
			t_type = "Value";
			break;
		case NODE_SET:
			t_type = "Set";
			break;
		case NODE_CONDITION:
			t_type = "Condition";
			break;
		case NODE_CALL:
			t_type = "Call";
			break;
		case NODE_COMPARISON_TYPE:
			t_type = "Comparison Type";
			break;
		case NODE_EXPRESSION:
			t_type = "Expression";
			break;
		case NODE_TERM:
			t_type = "Term";
			break;
		case NODE_FACTOR:
			t_type = "Factor";
			break;
		case NODE_OPERATOR_ARITHMETIC:
			t_type = "Operator Arithmetic";
			break;
		case NODE_SINGLE_VALUE:
			t_type = "Single Value";
			break;
		case NODE_NUMBER:
			t_type = "Number";
			break;
		case NODE_STRING:
			t_type = "String";
			break;
		case NODE_BOOL:
			t_type = "Boolean";
			break;
		case NODE_CLASS_MEMBER:
			t_type = "Class Member";
			break;
		case NODE_VALUE_KEYWORD:
			t_type = "Value Keyword";
			break;
		case NODE_REFERENCE_KEYWORD:
			t_type = "Reference";
			break;

	}
	return t_type;
}

ASTNode::ASTNode(ast_type type, string data) {
	this->type = type;
	this->data = data;
}

ASTNode::~ASTNode() {
	// TODO Auto-generated destructor stub
}

} /* namespace parser */
