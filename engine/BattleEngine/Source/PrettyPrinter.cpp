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

/**

cout << "\033[1;31mbold red text\033[0m\n";
cout << "\[\033[32m]Hello, \[\033[36m]colourful \[\033[33mworld!\033[0m]\nm";

**/

void PrettyPrinter::print(std::string in)
{
    std::cout << in;
}

void PrettyPrinter::print(std::string in, BASE_COLOR col)
{
    std::cout << "\e[0;"; // Reset
    std::cout << TEXT+col; // Text color.
    std::cout << "m"; // End parameters.
    std::cout << in; // Input.
    std::cout << "\033[0m"; // End format and endline.
}

void PrettyPrinter::print(std::string in, BASE_COLOR col, BASE_COLOR bg)
{
    std::cout << "\e[0;"
              << TEXT+col << ";"
              << BACKGROUND+bg
              << "m"
              << in
              << "\033[0m";
}

void PrettyPrinter::print_good(std::string in)
{
	PrettyPrinter::print(in, GREEN);
}

void PrettyPrinter::print_bad(std::string in)
{
	PrettyPrinter::print(in, RED);
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