/// booleannode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"

namespace trees
{

/**
 * This node subclass represents a boolean value.
 * \todo Find out why this node cannot emit itself in code generation.
 **/
class BooleanNode: public trees::AbstractSyntaxNode
{
public:

    /**
     * Constructor stub.
     **/
	virtual ~BooleanNode();
	
	/**
	 * Destructor stub.
	 **/
	BooleanNode();

    /**
     * Visitation implementation. As a very simple node, this one simply sets
     * the internal type to bool.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);

    /**
     * \todo Document. Is this raw source text?
     **/
	std::string raw;
	
	/**
	 * The actual boolean value of this node.
	 **/
	bool value;
};

} /* namespace trees */
