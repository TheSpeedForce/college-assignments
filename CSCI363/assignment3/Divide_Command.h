//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Divide_Command
 *
 * Command class for division, inherits Binary_Op_Command.
 * 
 */
class Divide_Command : public Binary_Op_Command 
{
public:

    // constructor
    Divide_Command (Stack <int> & s);

    // divide two numbers
    int evaluate (int n1, int n2) const;

    // destructor
    ~Divide_Command (void);
};

// include source file since template file
#include "Divide_Command.cpp"

#endif // !defined _DIVIDE_COMMAND_H_