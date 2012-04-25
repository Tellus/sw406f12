/*
 * RGR_List.h
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#pragma once

#include <math.h>
#include <list>

namespace engine
{
enum RGR_Enum{  ANY = 1,
                ENEMY = 2,
                ALLY = 4,
                OWNER = 8,
                ALL = 16,
                };
                    
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
    virtual ~RGR_List();
        
	/**
	 * Adds a single RGR to the list..
	 * \param Any value from the RGR_Enum.
	 * \note Duplicates are ignored.
	 **/
	void add_rgr(RGR_Enum);
	
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
	
private:
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
