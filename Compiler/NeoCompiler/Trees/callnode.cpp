/// callnode.cpp
///
/// This file contains ...

#include "callnode.h"

namespace trees
{

CallNode::CallNode() :
		identifier("")
{
	this->dynamic = true;
}

CallNode::~CallNode()
{ }

void CallNode::visit(typecheck::scope *current_scope)
{
	typecheck::Symbol *s = typecheck::SymbolTable::handle().lookup(current_scope, this->identifier, true);

	if (s == NULL)
		throw "Type Error: Undefined reference.";

	std::list<AbstractSyntaxNode*>::iterator it;
	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		(*it)->visit(current_scope);
	}


	FORMAT_TYPE t = s->assigns;

	if (t & typecheck::TypeReferenceAbility)
	{
		if (this->children.size() != 1)
			throw "Type Error: Ability calls take exactly 1 parameter";

		if (!(this->children.front()->type & typecheck::TypeReferenceCharacter))
			throw "Type Error: Invalid parameter in Ability call";
	}
	else if (t & typecheck::TypeReferenceEffect)
	{
		if (this->children.size() != 2)
			throw "Type Error: Effect calls take exactly 2 parameters";

		if (!((this->children.front()->type & typecheck::TypeReferenceCharacter) &&
				(this->children.back()->type & typecheck::TypeNumber)))
			throw "Type Error: Invalid parameter(s) in effect call";
	}
	else
	{
		throw "Call to non-callable type";
	}

	this->type = t | typecheck::TypeCall;
}

void CallNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Call (" << this->identifier
			<< ")" << std::endl;
	this->print_children(indent);
}

void CallNode::emit(codegen::EmissionData *data)
{
	if (data->data & codegen::EmitEffectList)
	{
		data->stream << "\t\tthis->add_effect(new " << this->identifier << "Effect(OWNER, ";

		this->emit_children(data, ", ");

		data->stream << "));\n";
	}
}

} /* namespace trees */
