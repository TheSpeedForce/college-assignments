//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"

/**
 * @class Binary_Op_Command
 *
 * Class to handle binary operations, inherits Expr_Command.
 * 
 */

class Binary_Op_Command : public Expr_Command 
{       
     public:   

        // constructor
        Binary_Op_Command (Stack <int> & s);

        void execute (void);    
            
        // pure virtual function to evaluate. 
        virtual int evaluate (int n1, int n2) const = 0;   

        // destructor
        ~Binary_Op_Command (void);
        
     private:   

        // create a stack for postfix evaluation
        Stack <int> & s_; 
};

// include source file since template file
#include "Binary_Op_Command.cpp"

#endif // !defined _BINARY_OP_COMMAND_H_