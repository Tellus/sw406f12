/*
 * RGR_List.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

void Ability::add_rgr(engine::RGR_Enum tar)
{
    if (this->has_rgr(tar)) return;
    
    this->rgr_mask |= tar;
    this->rgr_list.push_back(tar);
}

void Ability::remove_rgr(engine::RGR_Enum tar)
{
    // XOR will only remove it if it already exists, so we check existance.
    if (this->has_rgr(tar))
    {
        this->rgr_mask ^= tar;
        // Also remove from list.
        this->rgr_list.remove(tar);
    }
}

bool Ability::has_rgr(engine::RGR_Enum tar)
{
    return ((this->rgr_mask & tar) == tar);
}

void Ability::toggle_rgr(engine::RGR_Enum tar)
{
    if (this->has_rgr(tar)) this->rgr_list.remove(tar);
    else this->rgr_list.push_back(tar);
    
    this->rgr_mask ^= tar;
}

void Ability::set_rgrs(int tar)
{
    this->rgr_mask = tar;
    this->rgr_list.clear();
    
    int pos = 0;
    
    while (tar > 0)
    {
        if (tar & 1)
        {
            this->rgr_list.push_back(pow(2, pos));
        }
        
        pos++;
        tar = tar >> 1;
    }
}

void Ability::set_rgrs(RGR_Enum tar)
{
    this->rgr_mask = tar;
    this->rgr_list.clear();
    this->rgr_list.push_back(tar);
}
