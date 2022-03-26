//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"

/**
 * @class Expr_Command
 *
 * Class to create expression commands using Abstract Factory pattern.
 *  
 */

class Expr_Command_Factory  
{ 
public:   

    // constructor
    Expr_Command_Factory (void);   

    // pure virtual function to create number command
    virtual Number_Command * create_number_command (int num) = 0;  

    // pure virtual function to create add command
    virtual Add_Command * create_add_command (void) = 0;   
    
    // pure virtual function to create subtract command
    virtual Subtract_Command * create_subtract_command (void) = 0;  

    // pure virtual function to create multiply command
    virtual Multiply_Command * create_multiply_command (void) = 0;

    // pure virtual function to create divide command
    virtual Divide_Command * create_divide_command (void) = 0;
    
    // pure virtual function to create modulus command
    virtual Mod_Command * create_mod_command (void) = 0;

    // destructor
    virtual ~Expr_Command_Factory (void) = 0;   

private:  

    // prevent the following operations by any inherited class.
    Expr_Command_Factory (const Expr_Command_Factory &);
    const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
}; 

// include source file since template file
#include "Expr_Command_Factory.cpp"

#endif // !defined _EXPR_COMMAND_FACTORY_H_