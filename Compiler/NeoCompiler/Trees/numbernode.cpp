/// numbernode.cpp
///
/// This file contains ...

#include "numbernode.h"

namespace trees
{

NumberNode::NumberNode() :
		raw(""),
		value(0.0f)
{ }

NumberNode::~NumberNode()
{ }

void NumberNode::visit(typecheck::scope *current_scope)
{
	this->type = typecheck::TypeNumber;
}

void NumberNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << this->raw
			<< std::endl;
	this->print_children(indent);
}

void NumberNode::emit(codegen::EmissionData *data)
{
	data->stream << this->raw;
}

} /* namespace trees */
