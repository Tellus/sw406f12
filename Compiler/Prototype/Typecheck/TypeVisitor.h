/*
 * TypeVisitor.h
 *
 *  Created on: Apr 20, 2012
 *      Author: nattfari
 */

#ifndef TYPEVISITOR_H_
#define TYPEVISITOR_H_

#include "../Parser/ASTNode.h"

using namespace parser;

namespace typec {

class TypeVisitor {
public:
/*
	 visit_program();
	 visit_decl();
	 visit_assign();
	 visit_exp();
	 visit_list();
*/
	TypeVisitor();
	virtual ~TypeVisitor();
};
}
#endif /* TYPEVISITOR_H_ */
