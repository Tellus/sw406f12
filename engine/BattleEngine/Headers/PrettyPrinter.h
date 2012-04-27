/*
 * PrettyPrinter.h
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#pragma once
 
#include <string>
#include <iostream>
#include <vector>

namespace frontend
{

enum BASE_COLOR {   BLACK = 0,
                    RED = 1,
                    GREEN = 2,
                    YELLOW = 3,
                    BLUE = 4,
                    MAGENTA = 5,
                    CYAN = 6,
                    WHITE = 7
                };

enum COLOR_MOD {    TEXT = 30,
                    BACKGROUND = 40
                };


class PrettyPrinter
{
public:

    static void print(std::string in);

    /**
     * Prints coloured text to the standard output.
     * \param in The text to write.
     * \param col The colour (choose from BASE_COLOR choices).
     * \note Only complete string instances can be accepted right now.
     **/
    static void print(std::string in, BASE_COLOR col);
    
    /**
     * Prints coloured text to the standard output.
     * \param in The text to write.
     * \param col The colour (choose from BASE_COLOR choices).
     * \param bg The background colour to use (choose from BASE_COLOR).
     * \note Only complete string instances can be accepted right now.
     **/
    static void print(std::string in, BASE_COLOR col, BASE_COLOR bg);
    
    /**
     * Shorthand for print(in, GREEN);
     **/
    static void print_good(std::string in);
    
	/**
	 * Shorthand for print(in, RED);
	 **/
    static void print_bad(std::string in);
    
private:
    /**
     * We use the buffer to prep a string before sending it out into
     * the wild.
     **/
    static std::string _buffer;
	static std::vector<int> _params;
    
    static void _empty_buffer();
    static void _add_param(int param);
    static void _print_buffer();
    static void _add_text(std::string in);
    static void _do_print(std::vector<int> params, std::string in);
    
    /**
     *
     */
    static void _start_format();
    static void _end_format();
};

}
