/// booleanvaluenode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{


/// Children:
 // None
class ConditionNode: public trees::AbstractSyntaxNode
{
public:
	ConditionNode();
	virtual ~ConditionNode();

	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string op;
};

} /* namespace trees */
