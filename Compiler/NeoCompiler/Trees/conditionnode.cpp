/// booleanvaluenode.cpp
///
/// This file contains ...

#include "conditionnode.h"

namespace trees
{

ConditionNode::ConditionNode() :
		op("")
{ }

ConditionNode::~ConditionNode()
{ }

void ConditionNode::visit(typecheck::scope *current_scope)
{
	FORMAT_TYPE t = typecheck::MetatypeNone;
	std::list<AbstractSyntaxNode*>::iterator it;

	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		(*it)->visit(current_scope);

		if ((*it)->dynamic)
			this->dynamic = true;

		t |= (*it)->type;
		if (t != (*it)->type)
			throw "Type Error: Type mismatch in comparison";
	}

	if (this->op != "==" && t != typecheck::TypeNumber)
		throw "Invalid comparison";

	this->type = typecheck::TypeBool;
}

void ConditionNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Bexp (" << this->op
			<< ")" << std::endl;
	this->print_children(indent);
}
} /* namespace trees */
