/// stringnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

/**
 * This AST node represents any string literal from the source program.
 **/
class StringNode: public trees::AbstractSyntaxNode
{
public:
    /**
     * Stub constructor
     **/
	StringNode();
	
	/**
	 * Stub deconstructor.
	 **/
	virtual ~StringNode();

    /**
     * Visit implementation from AbstractSyntaxNode.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string raw, value;
};

} /* namespace trees */
