/// identifiernode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class IdentifierNode: public trees::AbstractSyntaxNode
{
public:
	IdentifierNode(std::string input);
	virtual ~IdentifierNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string id;
};

} /* namespace trees */
