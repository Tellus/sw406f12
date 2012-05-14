/*
 * EventCondition.h
 *
 *  Created on: 11/05/2012
 *      Author: Johannes
 */

#ifndef EVENT_CONDITION_H_
#define EVENT_CONDITION_H_

#include <string>
#include <boost/lexical_cast.hpp>

#include "RGR_Enum.h"
#include "RGR_List.h"

namespace engine
{

enum COMPARISON_ENUM{   LESS_THAN = 1,
                        GREATER_THAN = 2,
                        LESS_THAN_OR_EQUAL = 3,
                        GREATER_THAN_OR_EQUAL = 4,
                        EQUAL = 5,
                        NOT_EQUAL = 6};

/**
 * Event conditions are the newly-decided-upon methods of event handling. We
 * decided to reduce the complexity of events, shifting away from triggers and
 * focusing solely on criteria. An EventCondition represents a criteria and the
 * following action taken by that criteria.
 **/
class EventCondition
{
public:
    EventCondition();

    /**
     * Creates a new, ready, EventCondition.
     * \param trg The target of the condition comparison.
     * \param m The member of the target to test.
     * \param comp The comparison method to use.
     * \val The comparison value.
     **/
    EventCondition(RGR_Enum trg, std::string m, COMPARISON_ENUM comp, float val);

    /**
     * Creates a new EventCondition by attempting to parse a string in the
     * following format:
     * "RGR.MEMBER(<|>|==|<=|>=|!=)FLOAT".
     * \param to_parse a string in the format "RGR.MEMBER(<|>|==|<=|>=|!=)FLOAT"
     * \throw Throws a InvalidStringFormatException if the format is unsatisfactory.
     * \note Does not validate members or RGRIdentifier existance in a GameState.
     * depending on the input, you're looking at more run-time errors, although
     * most should be caught during execution.
     **/
    EventCondition(std::string to_parse);

    /**
     * The RGR to check the condition against (for example ENEMY for health).
     **/
    RGR_Enum target;
    
    /**
     * Name of the member Primarch you wan to check a condition on ("Health",
     * for example).
     **/
    std::string member;
    
    /**
     * The 
     **/
    float value;
    
    /**
     * The type of comparison to perform.
     **/
    COMPARISON_ENUM comparison;
    
    COMPARISON_ENUM str_to_enum(std::string in);
};

}

#endif // EVENT_CONDITION_H_
