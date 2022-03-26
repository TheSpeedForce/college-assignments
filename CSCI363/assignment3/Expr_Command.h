//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

/**
 * @class Expr_Command
 *
 * Class to create expression commands.
 *  
 */

class Expr_Command 
{ 
    public:  

        // constructor
        Expr_Command (void);

        // pure virtual function to execute
        virtual void execute (void) = 0;

        // deconstructor
        virtual ~Expr_Command (void) = 0;
};

// include source file since template file
#include "Expr_Command.cpp"

#endif // !defined _EXPR_COMMAND_H_