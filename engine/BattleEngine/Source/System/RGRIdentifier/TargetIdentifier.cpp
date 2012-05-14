/*
 * EnemyIdentificer.cpp
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#include "TargetIdentifier.h"

namespace engine
{

TargetIdentifier::TargetIdentifier()
{
	this->rgr = TARGET;
}

Character* TargetIdentifier::identify(GameState *from)
{
	return from->get_target();
}

}
