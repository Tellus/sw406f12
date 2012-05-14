/// arithmeticnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class ArithmeticNode: public trees::AbstractSyntaxNode
{
public:
	ArithmeticNode();
	virtual ~ArithmeticNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string op;
};

} /* namespace trees */
