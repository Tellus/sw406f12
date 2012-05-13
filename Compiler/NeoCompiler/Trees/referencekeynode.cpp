/// referencekeynode.cpp
///
/// This file contains ...

#include "referencekeynode.h"

namespace trees
{

ReferenceKeyNode::ReferenceKeyNode(std::string input) :
		id(input)
{
	this->dynamic = true;
}

ReferenceKeyNode::~ReferenceKeyNode()
{ }

void ReferenceKeyNode::visit(typecheck::scope *current_scope)
{
	typecheck::Symbol *s = typecheck::SymbolTable::handle().lookup(current_scope, this->id, true);

	if (s == NULL)
		throw "Type Error: Undefined reference.";

	this->type = s->assigns;
	this->reference = s->reference;
}

void ReferenceKeyNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Ref (" << this->id
			<< ")" << std::endl;
	this->print_children(indent);
}

void ReferenceKeyNode::emit(codegen::EmissionData *data)
{
	std::transform(this->id.begin(), this->id.end(), this->id.begin(), (int (*)(int))std::toupper);

	data->stream << this->id;
}

} /* namespace trees */
