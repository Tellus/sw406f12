/// assignmentnode.h
///
/// This file contains ...

#ifndef ASSIGNMENTNODE_H_
#define ASSIGNMENTNODE_H_

#include "abstractsyntaxnode.h"

namespace trees
{

/**
 * This node represents assignment in langname as we see it within Primarch
 * definitions.
 **/
class AssignmentNode: public trees::AbstractSyntaxNode
{
public:
    /**
     * Constructor stub.
     **/
	AssignmentNode();
	
	/**
	 * Destructor stub.
	 **/
	virtual ~AssignmentNode();

    /**
     * Visitation implementation. This one ensure that LHS and RHS match for an
     * acceptable assignment.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	
	/**
	 *
	 **/
	void emit(codegen::EmissionData *data);

    /**
     * Far as I can tell, what was assigned <b>to</b>.
     * \todo Confirm documentation.
     **/
	std::string identifier;
	
	/**
	 * The specific assignment type. Check the possible types in
	 * Token/tokentypes.h - for this particular member, any of type
	 * Tokentype<Something>Assign assign should do.
	 **/
	std::string assignment_type;
};

} /* namespace trees */
#endif /* ASSIGNMENTNODE_H_ */
