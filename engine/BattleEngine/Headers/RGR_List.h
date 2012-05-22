/*
 * RGR_List.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#ifndef RGR_LIST_H_
#define RGR_LIST_H_

#include <math.h>
#include <list>
#include <string>

#include "RGR_Enum.h"
#include "Exceptions/InvalidRGRException.h"

namespace engine
{

/**
 * RGR_List is a glorified std::list for RGR_Enum values. It also handles
 * converting to/from std::string/RGR_Enum and has a few speedy methods for
 * handling several enums at once.
 **/
class RGR_List
{
public:
    /**
     * Creates an empty list of RGR's.
     **/
    RGR_List();
    
    /**
     * Creates a list of RGR's as passed.
     * \param rogers A mask of RGR's to add during initialization.
     **/ 
    RGR_List(int rogers);
    
    /**
     * \todo Implement or unplement?
     **/
    virtual ~RGR_List();
        
	/**
	 * Adds a single RGR to the list..
	 * \param rgr Any value from the RGR_Enum.
	 * \note Duplicates are ignored.
	 **/
	void add_rgr(RGR_Enum rgr);
	
	/**
	 * Checks if a given RGR is already added.
	 * \param tar RGR to check for.
	 * \return True if the RGR is applied. False otherwise.
	 **/
    bool has_rgr(RGR_Enum tar);
    
    /**
     * Removes an RGR from the list.
     * \param tar RGR to remove.
     **/
    void remove_rgr(RGR_Enum tar);
    
    /**
     * Toggles a RGR in the list. If it's on, it's removed. Otherwise,
     * it's added.
     * \param tar The RGR to toggle.
     **/
    void toggle_rgr(RGR_Enum tar);
    
    /**
     * Set a completely new target mask.
     * \param tars New rgr (singular). Consider using set_rgrs(int).
     **/
    void set_rgrs(RGR_Enum tars);
	
	/**
	 * Set a completely new RGR mask.
	 * \param tars New mask.
	 **/
	void set_rgrs(int tars);
	
	/**
	 * Gets the list of RGR's as a list container.
	 * \return List of RGR's.
	 */
	std::list<RGR_Enum> get_as_list();
	
	/**
	 * Gets the list of RGR's as a mask.
	 * \return The RGR's as a mask.
	 * \note Use bitwise operations and the enum values of RGR_Enum to filter
	 * out single values.
	 * \note This method may be faster than using get_as_list() for large sets
	 * but cannot offer the convenience of simple for loops with iterators.
	 */
	int get_as_mask();
	
	/**
	 * Hard-coded method for getting string representations of enums. Naturally,
	 * this is solely for debugging purposes.
	 **/
	static std::string to_string(RGR_Enum in);
	
	/**
	 * Hard-coded method for getting enum representations from strings. Used
	 * by the string parsed version of EventCondition, among others.
	 **/
	static RGR_Enum to_enum(std::string in);
	
protected:
    /**
     * List of RGR's.
     **/
    std::list<RGR_Enum> rgr_list;

    /**
     * Mask of RGR's. We use a mask to very quickly acknowledge the existance of
     * a particular target instead of moving through the list.
     **/
    int rgr_mask;
};

}

#endif
