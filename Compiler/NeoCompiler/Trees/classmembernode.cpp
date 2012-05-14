/// classmembernode.cpp
///
/// This file contains ...

#include "classmembernode.h"

namespace trees
{

ClassMemberNode::ClassMemberNode()
{
	this->dynamic = true;
}

ClassMemberNode::~ClassMemberNode()
{ }

void ClassMemberNode::visit(typecheck::scope *current_scope)
{
	std::list<AbstractSyntaxNode*>::iterator it;
	typecheck::scope *s = current_scope;
	typecheck::SymbolTable &t = typecheck::SymbolTable::handle();

	if (s == &t.behaviour && this->children.size() != 2)
		throw "Type Error: Wrong listening type for behaviour";

	// TODO: Only first children should be global, optimally.

	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		(*it)->visit(s);
		s = (*it)->reference;
		this->type = (*it)->type;
	}

	if (this->children.size() == 1)
		this->dynamic = false;
}

void ClassMemberNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Dynamic value" << std::endl;
	this->print_children(indent);
}

void ClassMemberNode::emit(codegen::EmissionData *data)
{
	if (data->data == (codegen::EmitCharacter | codegen::EmitAbilityList))
	{
		data->stream << "\t\tthis->add_ability(new ";

		this->children.front()->emit(data);

		data->stream << "());\n";
	} // TODO: Any more special cases. All lists, basically.
	else if (data->data & codegen::EmitBehaviour)
	{
		this->emit_children(data, ", ");
	}
	else
	{
		this->emit_children(data, ".");
	}
}

} /* namespace trees */
