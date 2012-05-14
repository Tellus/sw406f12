/// setnode.cpp
///
/// This file contains ...

#include "setnode.h"

namespace trees
{

SetNode::SetNode()
{ }

SetNode::~SetNode()
{ }

void SetNode::visit(typecheck::scope *current_scope)
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
			throw "Type Error: Type mismatch in list";
	}

	if (t & typecheck::TypeList)
		throw "Type Error: Invalid nesting of lists, did you mean to use a list of pairs?";

	if (this->children.size() == 2 && this->children.front()->dynamic &&
			!this->children.back()->dynamic)
	{
		this->type = t | typecheck::TypePair;
		std::cout << "    TC: Pair resolved" << std::endl;
	}
	else
	{
		this->type = t | typecheck::TypeList;
		std::cout << "    TC: List resolved" << std::endl;
	}
}

void SetNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "List" << std::endl;
	this->print_children(indent);
}

void SetNode::emit(codegen::EmissionData *data)
{
	if (this->type & typecheck::TypeList)
	{
		this->emit_children(data);
	}
	else
	{
		if (data->data & codegen::EmitBehaviour)
		{
			data->stream << "\t\tthis->add_ratio(new BehaviourRatio(";

			std::string seperator = ", ";
			if (data->data & codegen::EmitNegativeList)
				seperator += "-1 * (";

			this->emit_children(data, seperator);

			if (data->data & codegen::EmitNegativeList)
				data->stream << ")";

			data->stream << "));\n";
		}
	}
}

} /* namespace trees */
