/// declarationnode.cpp
///
/// This file contains ...

#include "declarationnode.h"

namespace trees
{

DeclarationNode::DeclarationNode() :
		superclass(""),
		subclass(""),
		assignments()
{ }

DeclarationNode::~DeclarationNode()
{
	this->assignments.clear();
}

void DeclarationNode::visit(typecheck::scope *current_scope)
{
	typecheck::SymbolTable &table = typecheck::SymbolTable::handle();

	typecheck::Symbol *s = table.lookup(current_scope, this->subclass, false);
	if (s != NULL)
		throw "Duplicate declaration";

	s = table.lookup(current_scope, this->superclass, false);

	if (s != NULL)
	{
		table.add_symbol(current_scope, this->subclass, s->assigned_from, s->assigns, s->reference);
		std::cout << "TC: " << this->subclass << " declared as type " << this->superclass << std::endl;

		std::list<AbstractSyntaxNode*>::iterator it;
		for (it = this->children.begin(); it != this->children.end(); it++)
		{
			if (!this->unique_assignment(((AssignmentNode*)(*it))->identifier))
				throw "Type Error: Duplicate assignment";

			(*it)->visit(s->reference);
		}
		return;
	}

	throw "Type Error: Superclass not found";
}

void DeclarationNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Declaration (" << this->subclass << ": " << this->superclass
			<< ")" << std::endl;
	this->print_children(indent);
}

void DeclarationNode::emit(codegen::EmissionData *data)
{
	codegen::Generator &gen = codegen::Gen();

	data->stream << "class " << this->subclass << " : ";

	if (this->superclass == "Behaviour") { data->stream << "Full"; }

	data->stream << this->superclass;

	if (this->superclass == "Event") { data->stream << "Listener"; }

	data->stream << "\n{\npublic:\n\t" << this->subclass <<
			"()\n\t{\n";

	if (this->superclass == "Character")
	{
		data->stream << "\t\t// Explicit Data:\n";
		data->data = codegen::EmitCharacter;
	}
	else if (this->superclass == "Event")
	{

		data->data = codegen::EmitEvent;
		data->stream << "\t\t// Explicit Data:\n";
	}
	else if (this->superclass == "Behaviour")
	{
		data->data = codegen::EmitBehaviour;
		data->stream << "\t\t//Explicit Data:\n";
	}
	else if (this->superclass == "Ability")
	{

		data->data = codegen::EmitAbility;
		data->stream << "\t\t// Explicit Data:\n";
	}


	this->emit_children(data);

	data->stream << "\n\t\t// Automatically Inserted Data:\n";
	if (this->superclass == "Character")
	{
		gen.character_post(data->stream, this->assignments);
	}
	else if (this->superclass == "Ability")
	{
		gen.ability_post(data->stream, this->assignments);
	}
	else
		data->stream << "\t\t// None for this type.\n";

	data->stream << "\t}\n};\n";
}

bool DeclarationNode::unique_assignment(std::string id)
{
	std::list<std::string>::iterator it;

	for (it = this->assignments.begin(); it != this->assignments.end(); it++)
	{
		if (id == *it)
			return false;
	}

	this->assignments.push_back(id);

	return true;
}

} /* namespace trees */
