/*
 * PrettyPrinter.cpp
 *
 *  Created on: 27/04/2012
 *      Author: Johannes
 */

#include "PrettyPrinter.h" 

namespace frontend
{

std::string PrettyPrinter::_buffer = std::string();
std::vector<int> PrettyPrinter::_params = std::vector<int>();

void PrettyPrinter::print(std::string in)
{
    std::cout << in;
}

void PrettyPrinter::print(std::string in, FG_COLOR col)
{
    std::cout << "\e[0;"; // Reset
    std::cout << col; // Text color.
    std::cout << "m"; // End parameters.
    std::cout << in; // Input.
    std::cout << "\033[0m"; // End format and endline.
}

void PrettyPrinter::print(std::string in, FG_COLOR col, BG_COLOR bg)
{
    std::cout << "\e[0;"
              << col << ";"
              << bg
              << "m"
              << in
              << "\033[0m";
}

void PrettyPrinter::print_good(std::string in)
{
	PrettyPrinter::print(in, FG_GREEN);
}

void PrettyPrinter::print_bad(std::string in)
{
	PrettyPrinter::print(in, FG_RED);
}

void PrettyPrinter::_empty_buffer()
{
    PrettyPrinter::_buffer = "";
}

void PrettyPrinter::_add_param(int param)
{
    PrettyPrinter::_params.push_back(param);
}

void PrettyPrinter::_print_buffer()
{
    std::cout << PrettyPrinter::_buffer;
}

void PrettyPrinter::_add_text(std::string in)
{
    PrettyPrinter::_buffer += in;
}

void PrettyPrinter::_do_print(std::vector<int> params, std::string in)
{
    
}

}