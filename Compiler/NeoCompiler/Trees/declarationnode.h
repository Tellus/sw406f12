/// declarationnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"
#include "assignmentnode.h"

namespace trees
{

class DeclarationNode: public trees::AbstractSyntaxNode
{
public:
	DeclarationNode();
	virtual ~DeclarationNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string superclass, subclass;

private:
	bool unique_assignment(std::string id);

	std::list<std::string> assignments;
};

} /* namespace trees */
