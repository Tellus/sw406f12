/// stringnode.cpp
///
/// This file contains ...

#include "stringnode.h"

namespace trees
{

StringNode::StringNode() :
		raw(""),
		value("")
{ }

StringNode::~StringNode()
{ }

void StringNode::visit(typecheck::scope *current_scope)
{
	this->type = typecheck::TypeString;
}

void StringNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << this->raw << std::endl;
	this->print_children(indent);
}

void StringNode::emit(codegen::EmissionData *data)
{
	data->stream << "\"" << this->value << "\"";
}

} /* namespace trees */
