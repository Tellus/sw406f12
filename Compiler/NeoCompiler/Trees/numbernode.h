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
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string raw;
	double value;
};

} /* namespace trees */
