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
}

ASTNode::ASTNode(ast_type type, string data) {
	this->type = type;
	this->data = data;
}

ASTNode::~ASTNode() {
	// TODO Auto-generated destructor stub
}

} /* namespace parser */
