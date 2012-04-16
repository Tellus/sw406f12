/*
 * RGRIdentifier.h
 *
 *  Created on: 16/04/2012
 *      Author: Johannes
 */

#pragma once

namespace engine
{

class RGRIdentifier
{
public:
    int rgr;
    virtual Character *identify(GameState *from) = 0;
    RGRIdentifier();
};

}
