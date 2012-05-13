/// booleannode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class BooleanNode: public trees::AbstractSyntaxNode
{
public:
	virtual ~BooleanNode();
	BooleanNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);

	std::string raw;
	bool value;
};

} /* namespace trees */
