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
	void print(std::size_t indent = 0);

	std::string op;
};

} /* namespace trees */
