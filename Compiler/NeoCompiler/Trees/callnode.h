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
	CallNode();
	virtual ~CallNode();

	void visit(typecheck::scope *current_scope);
	void print(std::size_t indent = 0);
	void emit(codegen::EmissionData *data);

	std::string identifier;
};

} /* namespace trees */
#endif /* CALLNODE_H_ */
