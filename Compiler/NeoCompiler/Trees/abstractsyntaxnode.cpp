/// abstractsyntaxnode.cpp
///
/// This file contains ...

#include "abstractsyntaxnode.h"

namespace trees
{

AbstractSyntaxNode::AbstractSyntaxNode() :
		type(typecheck::MetatypeNone),
		dynamic(false),
		reference(NULL),
		children()
{ }

AbstractSyntaxNode::~AbstractSyntaxNode()
{
	std::list<AbstractSyntaxNode*>::iterator it;

	for (it = this->children.begin(); it != this->children.end(); it++)
		delete (*it);
}

AbstractSyntaxNode *AbstractSyntaxNode::add_child(AbstractSyntaxNode *child)
{
	this->children.push_back(child);
	return child;
}

void AbstractSyntaxNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Generic node" << std::endl;
	this->print_children(indent);
}

void AbstractSyntaxNode::visit(typecheck::scope *current_scope)
{
}

void AbstractSyntaxNode::emit(codegen::EmissionData *data)
{
	this->emit_children(data);
}

void AbstractSyntaxNode::emit_children(codegen::EmissionData *data, std::string seperator)
{
	std::list<AbstractSyntaxNode*>::iterator it;

	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		if (it != this->children.begin())
			data->stream << seperator;

		(*it)->emit(data);
	}

}

void AbstractSyntaxNode::print_indent(std::size_t indent)
{
	for (std::size_t i = 1; i < indent; i++)
	{
		std::cout << " | ";
	}

	if (indent)
		std::cout << " +-";
}

void AbstractSyntaxNode::print_children(std::size_t indent)
{
	std::list<AbstractSyntaxNode*>::iterator i;

	for (i = this->children.begin(); i != this->children.end(); i++)
	{
		(*i)->print(indent + 1);
	}
}

} /* namespace trees */
