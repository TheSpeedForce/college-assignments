//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Subtract_Command
 *
 * Command class for subtraction, inherits Binary_Op_Command.
 * 
 */
class Subtract_Command : public Binary_Op_Command 
{
public:

    //constructor
    Subtract_Command (Stack <int> & s);

    //subtract two numbers
    int evaluate (int n1, int n2) const;

    //destructor
    ~Subtract_Command(void);
};

// include source file since template file
#include "Subtract_Command.cpp"

#endif // !defined _SUBTRACT_COMMAND_H_
