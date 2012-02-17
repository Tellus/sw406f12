/*
 * Attribute.h
 *
 *  Created on: 17/02/2012
 *      Author: Ezphares
 */

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>

using namespace std;

class Attribute {
public:
	double initial;
	double current;
	string name;

	virtual void init(double value);

	Attribute(string name);
	Attribute(string name, double value);
	Attribute(Attribute* copy);

	virtual ~Attribute();
};

#endif /* ATTRIBUTE_H_ */
