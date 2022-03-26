#include "my_shared_lib.h"
#include <iostream>

//
// Print message
//
void print_message (const std::string & msg)
{
    std::cout << msg << std::endl;
}

//
// Constructor
//
Greeting::Greeting (void)
{}

//
// Destructor
//
Greeting::~Greeting (void)
{}

//
// Class method for printing message
//
void Greeting::say_message (const std::string & msg)
{
    std::cerr << msg << std::endl;
}