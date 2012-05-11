/*
 * RGRIdentifier.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#include "RGRIdentifier.h"

namespace engine {

RGRIdentifier::RGRIdentifier()
{
    this->_init();
}

RGRIdentifier::RGRIdentifier(int rgr_id)
{
    this->_init();
    
    this->rgr = (RGR_Enum)rgr_id;
}

RGRIdentifier::~RGRIdentifier()
{
	// TODO: Stub.
}

void RGRIdentifier::_init()
{

}

}
