/// identifiernode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

/**
 * Represents an identifier in langname.
 * \todo Figure out if this is LHS-only identification.
 **/
class IdentifierNode: public trees::AbstractSyntaxNode
{
public:
    /**
     * Creates a new identifier node, setting its dynamic value to true.
     **/
	IdentifierNode(std::string input);

    /**
     * Destructor stub.
     **/
	virtual ~IdentifierNode();

    /**
     * Type and scope visitor implementation.
     * \todo Figure out why an identifier checks references.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	
	/**
	 * Emites C++ code.
	 * For RGR's, outputs upper-case RGR's.
	 * For Behaviour and Event, output identifier in quotes.
	 * For anything else, just send the identifier through.
	 **/
	void emit(codegen::EmissionData *data);

    /**
     * Identifier in nice string format.
     **/
	std::string id;
};

} /* namespace trees */
