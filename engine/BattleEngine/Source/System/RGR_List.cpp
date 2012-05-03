/*
 * RGR_List.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#include "RGR_List.h"
 
namespace engine {
 
RGR_List::RGR_List()
{
	// Will reset all members.
	this->set_rgrs(0);
}

RGR_List::~RGR_List()
{
	// STUB.
}
 
void RGR_List::add_rgr(engine::RGR_Enum tar)
{
    if (this->has_rgr(tar)) return;
    
    this->rgr_mask |= tar;
    this->rgr_list.push_back(tar);
}

void RGR_List::remove_rgr(engine::RGR_Enum tar)
{
    // XOR will only remove it if it already exists, so we check existance.
    if (this->has_rgr(tar))
    {
        this->rgr_mask ^= tar;
        // Also remove from list.
        this->rgr_list.remove(tar);
    }
}

bool RGR_List::has_rgr(engine::RGR_Enum tar)
{
    return ((this->rgr_mask & tar) == tar);
}

void RGR_List::toggle_rgr(engine::RGR_Enum tar)
{
    if (this->has_rgr(tar)) this->rgr_list.remove(tar);
    else this->rgr_list.push_back(tar);
    
    this->rgr_mask ^= tar;
}

void RGR_List::set_rgrs(int tar)
{
    this->rgr_mask = tar;
    this->rgr_list.clear();
    
    int pos = 0;
    
    while (tar > 0)
    {
        if (tar & 1)
        {
			int rgr_tmp = static_cast<int>(pow(2.0, pos));
            this->rgr_list.push_back(RGR_Enum(rgr_tmp));
        }
        
        pos++;
        tar = tar >> 1;
    }
}

void RGR_List::set_rgrs(RGR_Enum tar)
{
    this->rgr_mask = tar;
    this->rgr_list.clear();
    this->rgr_list.push_back(tar);
}

std::list<RGR_Enum> RGR_List::get_as_list()
{
	return std::list<RGR_Enum>(this->rgr_list);
}

int RGR_List::get_as_mask()
{
	return this->rgr_mask;
}

std::string RGR_List::to_string(RGR_Enum in)
{
    switch (in)
    {
        case ANY:
            return "ANY";
        case ENEMY:
            return "ENEMY";
        case ALLY:
            return "ALLY";
        case OWNER:
            return "OWNER";
        case ALL:
            return "ALL";
        default:
            return "UNKNOWN";
    }
}

}
