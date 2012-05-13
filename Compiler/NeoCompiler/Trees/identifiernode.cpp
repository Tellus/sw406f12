/// identifiernode.cpp
///
/// This file contains ...

#include "identifiernode.h"

namespace trees
{

IdentifierNode::IdentifierNode(std::string input) :
		id(input)
{
	this->dynamic = true;
}

IdentifierNode::~IdentifierNode()
{ }

void IdentifierNode::visit(typecheck::scope *current_scope)
{
	typecheck::Symbol *s = typecheck::SymbolTable::handle().lookup(current_scope, this->id, true);

	if (s == NULL)
		throw "Type Error: Undefined reference.";

	this->type = s->assigns;
	this->reference = s->reference;

}

void IdentifierNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "ID (" << this->id
			<< ")" << std::endl;
	this->print_children(indent);
}

void IdentifierNode::emit(codegen::EmissionData *data)
{
	if (this->id == "target" || this->id == "owner")
		std::transform(this->id.begin(), this->id.end(), this->id.begin(), (int (*)(int))std::toupper);
	else if (data->data & codegen::EmitBehaviour)
		this->id = "\"" + this->id + "\"";

	data->stream << this->id;
}

} /* namespace trees */
