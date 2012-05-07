/*
 * ResourceEvent.h
 *
 *  Created on: 07/05/2012
 *      Author: Johannes
 */

#pragma once

#include "PrimarchEvent.h"

namespace engine {

class ResourceEvent : public PrimarchEvent
{

	/**
	 * Returns "RESOURCE_GENERIC";
	 **/
	std::string get_type();

};

}