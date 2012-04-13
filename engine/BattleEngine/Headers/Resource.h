/*
 * Resource.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Attribute.h"

#include <algorithm>

namespace engine {

class Resource: public engine::Attribute {
public:
	int maximum, minimum, initial_minimum;

	void deplete(int amount);
	void regain(int amount);
	void modify_minimum(int amount);
	virtual void reset();
	virtual void modify(int amount);

	/* At maximum = -1, set it to value */
	Resource(int value, int maximum = -1, int minimum = 0);
	Resource(Resource *copy);
	virtual ~Resource();
};

} /* namespace engine */
#endif /* RESOURCE_H_ */
