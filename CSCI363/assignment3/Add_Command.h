//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Add_Command
 *
 * Command class for addition, inherits Binary_Op_Command class.
 *  
 */

class Add_Command : public Binary_Op_Command 
{
public:

    // constructor
    Add_Command (Stack <int> & s);

    // add two numbers together
    int evaluate (int n1, int n2) const;

    // destructor
    ~Add_Command (void);
};

// include source file since template file
#include "Add_Command.cpp"

#endif // !defined _ADD_COMMAND_H_

