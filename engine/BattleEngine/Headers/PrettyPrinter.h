/*
 * PrettyPrinter.h
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#ifndef PRETTY_PRINTER_H_
#define PRETTY_PRINTER_H_
 
#include <string>
#include <iostream>
#include <vector>

#ifdef WIN32
#include "PrettyPrinter_WIN32.h"
#else
#include "PrettyPrinter_BASH.h"
#endif

namespace frontend
{

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
    static void print(std::string in, FG_COLOR col);
    
    /**
     * Prints coloured text to the standard output.
     * \param in The text to write.
     * \param col The colour (choose from BASE_COLOR choices).
     * \param bg The background colour to use (choose from BASE_COLOR).
     * \note Only complete string instances can be accepted right now.
     **/
    static void print(std::string in, FG_COLOR col, BG_COLOR bg);
    
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

#endif
