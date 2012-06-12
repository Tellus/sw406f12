/// valuekeynode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class ValueKeyNode: public trees::AbstractSyntaxNode
{
public:
	ValueKeyNode();
	virtual ~ValueKeyNode();

	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string value;
};

} /* namespace trees */
