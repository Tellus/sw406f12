/// valuekeynode.cpp
///
/// This file contains ...

#include "valuekeynode.h"

namespace trees
{

ValueKeyNode::ValueKeyNode() :
		value("")
{
	this->dynamic = true;
}

ValueKeyNode::~ValueKeyNode()
{ }

void ValueKeyNode::visit(typecheck::scope *current_scope)
{
	this->type = typecheck::TypeTargetGroup;
}

void ValueKeyNode::print(std::size_t indent)
{
	this->print_indent(indent);
	std::cout << "Special value (" << this->value
			<< ")" << std::endl;
	this->print_children(indent);
}

void ValueKeyNode::emit(codegen::EmissionData *data)
{
	std::transform(this->value.begin(), this->value.end(), this->value.begin(), (int (*)(int))std::toupper);

	if (data->data & codegen::EmitTargetsList)
	{
		data->stream << "\t\tthis->add_rgr(" << this->value << ");\n";
	}
}

} /* namespace trees */
