#pragma once

#include "types.h"

#include <string>
#include <map>

namespace typecheck
{

struct Symbol; // Forward declaration
typedef std::map<std::string, Symbol*> scope;
struct Symbol
{
	FORMAT_TYPE assigned_from;
	FORMAT_TYPE assigns;
	scope *reference;
	Symbol(FORMAT_TYPE af, FORMAT_TYPE a, scope *r) :
		assigned_from(af),
		assigns(a),
		reference(r)
	{ }
};

} /* namespace typecheck */
