/*
 * EventCondition.cpp
 *
 *  Created on: 11/05/2012
 *      Author: Johannes
 */
 
#include "EventCondition.h"

namespace engine
{

EventCondition::EventCondition(RGR_Enum trg, std::string m, COMPARISON_ENUM comp, float val):
    target(trg),
    member(m),
    value(val),
    comparison(comp)
{
// Nothing to see here!
}

EventCondition::EventCondition(std::string to_parse)
{
    // cout << "Parsing '" << to_parse << "'\n";

    // Location of the dot between RGR and member.    
    size_t mref = to_parse.find_first_of('.');
    
    // Take out RGR.
    std::string rgr = to_parse.substr(0, mref);
    
    // cout << "RGR: '" << rgr << "'\n";
    
    // TODO: Convert to Enum.
    
    // Reduce.
    to_parse = to_parse.substr(mref+1);
    
    // Take out member.
    std::string member = "";
    
    for (std::string::iterator iter = to_parse.begin();
           iter < to_parse.end();
           iter++)
    {
        if (('a' <= (*iter) && (*iter) <= 'z') ||
            ('A' <= (*iter) && (*iter) <= 'Z'))
            member += (*iter);
        else
            iter = to_parse.end();
    }
    to_parse = to_parse.substr(member.length());
    
    // cout << "Member: '" << member << "'\n";
    
    std::string comp = to_parse.substr(0,1);
    to_parse = to_parse.substr(1);
 
    if (!('0' <= to_parse[0] && to_parse[0] <= '9'))
    {
        comp += to_parse[0];
        to_parse = to_parse.substr(1);
    }
    
    std::string val = to_parse;
    
    // cout << "Comparison: '" << comp << "'\n";
    // cout << "Value: '" << val << "'\n";
    
    float value = boost::lexical_cast<float>(val);
    
    // cout << "Value as float: '" << value << "'\n";
    
    this->value = value;
    this->comparison = this->str_to_enum(comp);
    this->member = member;
    this->target = RGR_List::to_enum(rgr);
}

COMPARISON_ENUM str_to_enum(std::string in)
{
    // UGLYNESS INCOMING!
    if (in == "==") return EQUAL;
    if (in == "!=") return NOT_EQUAL;
    if (in == "<" ) return LESS_THAN;
    if (in == ">" ) return GREATER_THAN;
    if (in == "<=") return LESS_THAN_OR_EQUAL;
    if (in == ">=") return GREATER_THAN_OR_EQUAL;
/*
    switch(in)
    {
        case "==": return EQUAL;
        case "!=": return NOT_EQUAL;
        case "<" : return LESS_THAN;
        case ">" : return GREATER_THAN;
        case "<=": return LESS_THAN_OR_EQUAL;
        case ">=": return GREATER_THAN_OR_EQUAL;
        default: throw exception("Bad input!");
    }
    */
    throw std::exception();
}

}
