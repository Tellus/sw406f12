/*
 * Attribute.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

namespace engine {

class Attribute {
public:
	int current, initial;

	/* Modifies current on Attribute, modifies maximum on Resource */
	virtual void modify(int amount);
	/* Resets current on Attribute, boundaries on Resource */
	virtual void reset();

	Attribute(int value);
	Attribute(Attribute *copy);
	virtual ~Attribute();
};

} /* namespace engine */
#endif /* ATTRIBUTE_H_ */
