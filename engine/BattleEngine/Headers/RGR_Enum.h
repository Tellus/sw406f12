/*
 * RGR_Enum.h
 *
 *  Created on: 03/05/2012
 *      Author: Johannes
 */

#ifndef RGR_ENUM_H_
#define RGR_ENUM_H_

namespace engine
{

enum RGR_Enum{  ANY = 1,
                ENEMY = 2,
                ALLY = 4,
                OWNER = 8,
                ALL = 16,
				TARGET = 32,
				SELF = OWNER
                };

}

#endif
