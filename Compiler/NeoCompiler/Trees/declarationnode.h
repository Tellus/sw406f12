/// declarationnode.h
///
/// This file contains ...

#pragma once

#include "abstractsyntaxnode.h"
#include "assignmentnode.h"

namespace trees
{

/**
 *
 **/
class DeclarationNode: public trees::AbstractSyntaxNode
{
public:
    /**
     * Creates a new DeclarationNode with non-existant super and subclasses.
     **/
	DeclarationNode();
	
	/**
	 * Destructor. Clears the list of assignments... why? It's non-pointer, they
	 * should disappear on their own.
	 **/
	virtual ~DeclarationNode();

	void visit(typecheck::scope *current_scope);
	
	/**
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	
	/**
	 * Code generation part of the node. Emites C++ code equivalent to this
	 * node's contents. In the case of declarations, the header part of its
	 * target is emitted. Type is based in subclass (... what?!).
	 * \param data Unknown. Document.
	 * \todo Document the parameters.
	 **/
	void emit(codegen::EmissionData *data);

    /**
     * Class that this declaration inherits from. There is always inheritance
     * in langname declarations (everything is a Primarch).
     **/
	std::string superclass;
	
	/**
	 * Contrary to what the member name suggests, this is actually *this*
	 * declaration's class.
	 **/
	std::string subclass;

private:
    /**
     * Checks to see if a given assignment has already been registered.
     * \param id The assignment to check for.
     * \return True if the assignment is unique. False otherwise.
     * \note The assignment is added to the list of assignments.
     **/
	bool unique_assignment(std::string id);

    /**
     * Unknown. Guess: list of known declarations/assignments.
     * \todo Document this member.
     **/
	std::list<std::string> assignments;
};

} /* namespace trees */
