/*
 * Resource.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "Attribute.h"

class Resource: public Attribute {
public:
	double maximum;

	virtual void init(double value);
	double percent();

	Resource(string name);
	Resource(string name, double value);
	Resource(Resource* copy);
	virtual ~Resource();
};

#endif /* RESOURCE_H_ */
