/// abstractsyntaxnode.h
///
/// This file contains ...

#pragma once

#include "../SymbolTables/symboltable.h"
#include "../CodeGeneration/emissiondata.h"
#include "../CodeGeneration/generator.h"

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

namespace trees
{

/**
 * Base class for all nodes in the AST. Recall that in visitor, all nodes are
 * based on a common ancestor to have a general interface, while implementing
 * separate acceptance implementations.
 **/
class AbstractSyntaxNode
{
public:
    /**
     * Create a new node with an "none" type and default contents.
     * It is basically unusable... so why isn't it actually <b>abstract</b>
     * like visitor suggests?
     **/
	AbstractSyntaxNode();
	
	/**
	 * Destroys all underlying children. Clean.
	 **/
	virtual ~AbstractSyntaxNode();

    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	virtual void print(std::size_t indent = 0);
	
	/**
	 * Part of the visitor pattern. Unused in super class so why in the fucking
	 * <b>hell</b> isn't it abstract to create just a smidgen of proper design?
	 **/
	virtual void visit(typecheck::scope *current_scope);
	
	/**
	 * Emits target code for ths node and its children, recursively.
	 * \todo Figure out what the data parameter actually is.
	 **/
	virtual void emit(codegen::EmissionData *data = NULL);
	
	/**
	 * Adds a new child to this node.
	 * \param child AbstractSyntaxNode to add.
	 * \return The child itself. Good for chaining.
	 **/
	AbstractSyntaxNode *add_child(AbstractSyntaxNode *child);

    /**
     * The type that this node references or is. See SymbolTables/types.h for
     * a complete list.
     **/
	FORMAT_TYPE type;
	
	/**
	 * \todo Write. I'm not sure what we mean by dynamic yet.
     **/
	bool dynamic;
	
	/**
	 * Reference to the object that this node represents.
	 * \todo Verify documentation.
	 **/
	typecheck::scope *reference;

protected:
    /**
     * Recursively calls the emit method on each of this node's children.
     * \todo Figure out what exactly the parameters are used for.
     **/
	void emit_children(codegen::EmissionData *data, std::string seperator = "");

    /**
     * Prints a series of indentation markers to stdout.
     * \param indent The number of indentations to perform.
     **/
	void print_indent(std::size_t indent);

    /**
     * Recursively calls AbstractSyntaxNode::print() on each of this node's
     * children.
     * \param indent Amount of indentation to perform on each child before
     * printing.
     **/
	void print_children(std::size_t indent);

    /**
     * List of direct descendants (children) of this node. I.e. it should be
     * very empty if this node is a leaf.
     **/
	std::list<AbstractSyntaxNode*> children;
};

} /* namespace trees */
