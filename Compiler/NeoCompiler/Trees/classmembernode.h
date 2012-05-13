/// classmembernode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

class ClassMemberNode: public trees::AbstractSyntaxNode
{
public:
	ClassMemberNode();
	virtual ~ClassMemberNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);
};

} /* namespace trees */
