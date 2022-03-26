//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 *
 * Class to create commands for infix to postfix expression. Inherits Expr_Command_Factory.
 * 
 */

class Stack_Expr_Command_Factory : public Expr_Command_Factory  
{
    public:  

        // constructor
        Stack_Expr_Command_Factory (Stack <int> & stack);   

        Number_Command * create_number_command (int num);
        
        Add_Command * create_add_command (void);   

        Subtract_Command * create_subtract_command (void);

        Divide_Command * create_divide_command (void); 

        Multiply_Command * create_multiply_command (void); 

        Mod_Command * create_mod_command (void); 

        // destructor
        ~Stack_Expr_Command_Factory (void);
    
    private:   

        //make a stack object
        Stack <int> & stack_;      
};

// include source file since template file
#include "Stack_Expr_Command_Factory.cpp"

#endif // !defined _STACK_EXPR_COMMAND_FACTORY_H_