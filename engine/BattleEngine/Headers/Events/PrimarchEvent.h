/*
 * PrimarchEvent.h
 *
 *  Created on: 06/05/2012
 *      Author: Johannes
 */

#pragma once

#include "GameEvent.h"

namespace engine {

class PrimarchEvent : public GameEvent
{

	/**
	 * Returns "PRIMARCH;GENERIC";
	 **/
	std::string get_type();

};

}