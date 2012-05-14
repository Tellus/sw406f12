/// arithmeticnode.cpp
///
/// This file contains ...

#include "arithmeticnode.h"

namespace trees
{

ArithmeticNode::ArithmeticNode() :
		op("")
{
}

ArithmeticNode::~ArithmeticNode()
{ }

void ArithmeticNode::visit(typecheck::scope *current_scope)
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

	switch (t)
	{
		case (typecheck::TypeString):
		{
			if (this->op != "+")
				throw "Type Error: Operator not supported for this type";
			break;
		}
		case (typecheck::TypeNumber):
		{
			break;
		}
		default:
			throw "Type Error: Operator not supported for this type";
	}

	this->type = t;
}

void ArithmeticNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Aexp (" << this->op
			<< ")" << std::endl;
	this->print_children(indent);
}

void ArithmeticNode::emit(codegen::EmissionData *data)
{
	data->stream << "(";

	this->children.front()->emit(data);
	data->stream << " " << this->op << " ";
	this->children.back()->emit(data);

	data->stream << ")";
}

} /* namespace trees */
