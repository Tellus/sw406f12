/// numbernode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class NumberNode: public trees::AbstractSyntaxNode
{
public:
	NumberNode();
	virtual ~NumberNode();

	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string raw;
	double value;
};

} /* namespace trees */
