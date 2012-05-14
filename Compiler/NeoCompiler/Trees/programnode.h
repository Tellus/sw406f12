/// programnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"
#include "declarationnode.h"

namespace trees
{

class ProgramNode: public trees::AbstractSyntaxNode
{
public:
	ProgramNode();
	virtual ~ProgramNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);
};

}
