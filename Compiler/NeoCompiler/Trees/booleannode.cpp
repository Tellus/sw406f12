/// booleannode.cpp
///
/// This file contains ...

#include "booleannode.h"

namespace trees
{

BooleanNode::BooleanNode() :
		raw(""),
		value(false)
{ }

BooleanNode::~BooleanNode()
{ }

void BooleanNode::visit(typecheck::scope *current_scope)
{
	this->type = typecheck::TypeBool;
}

void BooleanNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << this->raw << std::endl;
	this->print_children(indent);
}

} /* namespace trees */
