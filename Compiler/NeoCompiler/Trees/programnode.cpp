/// programnode.cpp
///
/// This file contains ...

#include "programnode.h"

namespace trees
{

ProgramNode::ProgramNode()
{ }

ProgramNode::~ProgramNode()
{ }

void ProgramNode::visit(typecheck::scope *current_scope)
{
	std::cout << "Typechecking program." << std::endl;

	std::list<AbstractSyntaxNode*>::iterator it;

	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		(*it)->visit(current_scope);
	}


	std::cout << "Typechecking successful." << std::endl;
}

void ProgramNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Program" << std::endl;
	this->print_children(indent);
}

void ProgramNode::emit(codegen::EmissionData *data)
{
	codegen::EmissionData *em = new codegen::EmissionData();
	std::list<AbstractSyntaxNode*>::iterator it;
	int c = 0;

	em->data = codegen::EmitNone;
	em->stream.open("generated.h", std::ios::out);

	em->stream << "#pragma once\n#include \"" << codegen::EmitHeaderDirectory <<
			"Engine.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"SimpleWinCondition.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"Character.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"Ability.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"Attribute.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"Resource.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"Behaviour.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"FullBehaviour.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"BehaviourRatio.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"EventListener.h\"\n#include \"" << codegen::EmitHeaderDirectory <<
			"example_ruleset.h\"\n" <<
			"using namespace engine;\n" <<
			"using namespace testbattle;\n" <<
			"namespace generated\n{\n";

	this->emit_children(em);


	em->stream << "void run();\n" <<
			"} /* namespace generated */" << std::endl;

	em->stream.close();

	em->stream.open("generated.cpp", std::ios::out);

	em->stream << "#include \"generated.h\"\n" <<
			"namespace generated\n{\n" <<
			"void run()\n{\n" <<
			"\tengine::Engine *game = new engine::Engine();\n" <<
			"\tgame->win_condition = new SimpleWinCondition();\n";

	for (it = this->children.begin(); it != this->children.end(); it++)
	{
		DeclarationNode *dec = (DeclarationNode*)(*it);
		if (dec->superclass == "Character")
		{
			em->stream << "\tgame->add_character(new " << dec->subclass << "());\n";
			if (++c == 2) // We're only dueling for now.
				break;
		}
	}

	em->stream << "\tgame->run();\n" <<
			"}\n} /* namespace generated */" << std::endl;

	em->stream.close();
}

} /* namespace trees */
