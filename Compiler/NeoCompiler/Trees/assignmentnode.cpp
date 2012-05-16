/// assignmentnode.cpp
///
/// This file contains ...

#include "assignmentnode.h"

namespace trees
{

AssignmentNode::AssignmentNode() :
		identifier(""),
		assignment_type("")
{ }

AssignmentNode::~AssignmentNode()
{ }

void AssignmentNode::visit(typecheck::scope *current_scope)
{
	typecheck::SymbolTable &table = typecheck::SymbolTable::handle();

	typecheck::Symbol *s = table.lookup(current_scope, this->identifier, false);
	if (s == NULL)
		throw "Type Error: Invalid target of assignment";

	std::cout << "  TC: Assigning " << this->identifier << std::endl;

	this->children.front()->visit(current_scope);

	FORMAT_TYPE t = this->children.front()->type;

	if ((t & typecheck::TypePair) && !(t & typecheck::TypeList))
	{
		t = ((t & ~typecheck::TypePair) | typecheck::TypeList);
	}

	if (t != s->assigned_from)
		throw "Type Error: Invalid assignment type";

	this->type = s->assigned_from;

	if ((this->type & typecheck::MetatypeReference) && (!this->type & typecheck::TypeReferenceEvent))
	{
		// This should make sure only event listeners can be deep-referenced.
		if (this->children.front()->dynamic)
			throw "Type Error: Deep-reference to static object.";
	}

	return;
}

void AssignmentNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Assignment (" << this->identifier
			<< ")" << std::endl;
	this->print_children(indent);
}

void AssignmentNode::emit(codegen::EmissionData *data)
{
	switch (data->data)
	{
		case codegen::EmitCharacter:
			if (this->type == typecheck::TypeNumber)
			{
				if (this->identifier == "health" || this->identifier == "mana")
				{
					data->stream << "\t\tthis->add_resource(new Resource(\"" << this->identifier <<
							"\", 0, ";

					this->emit_children(data);

					data->stream << "));\n";
				}
				else
				{
					data->stream << "\t\tthis->add_attribute(new Attribute(\"" << this->identifier <<
							"\", ";

					this->emit_children(data);

					data->stream << "));\n";
				}
			}
			else if (this->type == typecheck::TypeString)
			{
				data->stream << "\t\tthis->" << this->identifier << " = ";

				this->emit_children(data);

				data->stream << ";\n";
			}
			else if (this->type == (typecheck::TypeList | typecheck::TypeReferenceAbility))
			{
				data->data |= codegen::EmitAbilityList;

				this->emit_children(data);

				data->data &= codegen::EmitClass;
			}
			else if (this->type == (typecheck::TypeList | typecheck::TypeReferenceEvent))
			{
				data->data |= codegen::EmitEventList;

				this->emit_children(data);

				data->data &= codegen::EmitClass;
			}
			else if (this->identifier == "behaviour")
			{
				data->stream << "\t\tthis->behaviour = new ";

				this->emit_children(data);

				data->stream << "();\n";
			}

			break;
		case codegen::EmitAbility:
			if (this->type == typecheck::TypeString)
			{
				data->stream << "\t\tthis->name = ";

				this->emit_children(data);

				data->stream << ";\n";
			}
			else if (this->identifier == "mana_cost")
			{
				data->stream << "\t\tthis->cost_mana = ";

				this->emit_children(data);

				data->stream << ";\n";
			}
			else if (this->identifier == "health_cost")
			{
				data->stream << "\t\tthis->cost_health = ";

				this->emit_children(data);

				data->stream << ";\n";
			}
			else if (this->identifier == "targets")
			{
				data->data |= codegen::EmitTargetsList;

				this->emit_children(data);

				data->data &= codegen::EmitClass;
			}
			else if (this->identifier == "effects")
			{
				data->data |= codegen::EmitEffectList;

				this->emit_children(data);

				data->data &= codegen::EmitClass;

			}
			break;
		case codegen::EmitBehaviour:
			if (this->identifier == "negative")
				data->data |= codegen::EmitNegativeList;

			this->emit_children(data);

			data->data &= codegen::EmitClass;
			break;

		case codegen::EmitEvent:
			if (this->identifier == "action")
			{
				data->stream << "\t\tthis->set_action(new ";

				this->emit_children(data);

				data->stream << ");\n";
			}
			else if (this->identifier == "condition")
			{
				data->stream << "\t\tthis->set_condition(";
				data->data |= codegen::EmitEventCondition;

				this->emit_children(data);

				data->data &= codegen::EmitClass;
				data->stream << ");\n";
			}
			break;
		// TODO: Other cases
	}
}

} /* namespace trees */
