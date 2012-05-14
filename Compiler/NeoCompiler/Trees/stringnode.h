/// stringnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class StringNode: public trees::AbstractSyntaxNode
{
public:
	StringNode();
	virtual ~StringNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string raw, value;
};

} /* namespace trees */
