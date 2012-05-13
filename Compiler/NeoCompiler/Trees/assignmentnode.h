/// assignmentnode.h
///
/// This file contains ...

#ifndef ASSIGNMENTNODE_H_
#define ASSIGNMENTNODE_H_

#include "abstractsyntaxnode.h"

namespace trees
{

class AssignmentNode: public trees::AbstractSyntaxNode
{
public:
	AssignmentNode();
	virtual ~AssignmentNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string identifier, assignment_type;
};

} /* namespace trees */
#endif /* ASSIGNMENTNODE_H_ */
