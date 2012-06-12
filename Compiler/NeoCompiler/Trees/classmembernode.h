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
    /**
     * Initialises a ClassMemberNode with dynamic set to true.
     **/
	ClassMemberNode();
	
	/**
	 * Destructor stub.
	 **/
	virtual ~ClassMemberNode();

	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);
};

} /* namespace trees */
