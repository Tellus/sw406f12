/// setnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class SetNode: public trees::AbstractSyntaxNode
{
public:
	SetNode();
	virtual ~SetNode();

	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);
};

} /* namespace trees */

