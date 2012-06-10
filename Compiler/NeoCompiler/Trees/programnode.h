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
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);
};

}
