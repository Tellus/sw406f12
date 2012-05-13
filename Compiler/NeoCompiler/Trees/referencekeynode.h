/// referencekeynode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class ReferenceKeyNode: public trees::AbstractSyntaxNode
{
public:
	ReferenceKeyNode(std::string input);
	virtual ~ReferenceKeyNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string id;
};

} /* namespace trees */
