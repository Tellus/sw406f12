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

    /**
     * Constructor stub.
     **/
	ArithmeticNode();
	
	/**
	 * Deconstructor stub.
	 **/
	virtual ~ArithmeticNode();

    /**
     * Visitor implementation. This version checks to ensure that both left
     * and right operands of this operator are valid. Furthermore, it tests
     * that in the case of string concatenation, only "+" operations are
     * attempted.
     * \param current_scope Scope from which we are performing the type check.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	
	/**
	 * Emits equivalent C++ code to what the source was. In the case of
	 * aritmetics, this is straightforward. For non-parentheses, emitting left
	 * child, then operator, then right child - for parentheses, emit child
	 * within parentheses.
	 **/
	void emit(codegen::EmissionData *data);

    /**
     * The actual operator in string format.
     **/
	std::string op;
};

} /* namespace trees */
