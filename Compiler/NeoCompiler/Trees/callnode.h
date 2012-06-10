/// callnode.h
///
/// This file contains ...

#ifndef CALLNODE_H_
#define CALLNODE_H_

#include "abstractsyntaxnode.h"

namespace trees
{


class CallNode: public trees::AbstractSyntaxNode
{
public:
    /**
     * Initialises a new CallNode instance. Sets dynamic to true.
     **/
	CallNode();
	
	/**
	 * Destructor stub.
	 **/
	virtual ~CallNode();

    /**
     * Visitation implementation. This one simply checks to see that only
     * an Ability or Effect is called, and that their parameters are correct.
     * \param current_scope The scope we're performing the check in.
     **/
	void visit(typecheck::scope *current_scope);
	
    /**
     * Recursively prints this node and its children to stdout.
     * \param indent Number of indentations to perform on print.
     **/
	void print(std::size_t indent = 0);
	
	/**
	 * Emites C++ code. For effects, simply constructs and adds a new effect to
	 * the Ability being defined. For events... dunno.
	 * \todo Document how this node emits for Event objects.
	 **/
	void emit(codegen::EmissionData *data);

    /**
     * Name of the call - I'm guessing it matches the Primarch it references.
     **/
	std::string identifier;
};

} /* namespace trees */
#endif /* CALLNODE_H_ */
