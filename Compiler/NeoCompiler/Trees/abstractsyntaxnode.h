/// abstractsyntaxnode.h
///
/// This file contains ...

#pragma once

#include "../SymbolTables/symboltable.h"
#include "../CodeGeneration/emissiondata.h"
#include "../CodeGeneration/generator.h"

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

namespace trees
{

class AbstractSyntaxNode
{
public:
	AbstractSyntaxNode();
	virtual ~AbstractSyntaxNode();

	virtual void print(std::size_t indent = 0);
	virtual void visit(typecheck::scope *current_scope);
	virtual void emit(codegen::EmissionData *data = NULL);
	AbstractSyntaxNode *add_child(AbstractSyntaxNode *child);

	FORMAT_TYPE type;
	bool dynamic;
	typecheck::scope *reference;

protected:
	void emit_children(codegen::EmissionData *data, std::string seperator = "");
	void print_indent(std::size_t indent);
	void print_children(std::size_t indent);
	std::list<AbstractSyntaxNode*> children;
};

} /* namespace trees */
