/*
 * Resource.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Attribute.h"

namespace engine {

class Resource: public engine::Attribute {
public:
	Resource();
	virtual ~Resource();
};

} /* namespace engine */
#endif /* RESOURCE_H_ */
