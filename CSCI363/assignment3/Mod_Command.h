
//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Binary_Op_Command.h"

/**
 * @class Mod_Command
 *
 * Command class for finding remainder, inherits Binary_Op_Command.
 * 
 */
class Mod_Command : public Binary_Op_Command 
{
public: 

    // constructor
    Mod_Command (Stack <int> & s);

    // function to get remainder of two numbers
    int evaluate (int n1, int n2) const;

    // destructor
    ~Mod_Command (void);
};

// include source file since template file
#include "Mod_Command.cpp"

#endif // !defined _MOD_COMMAND_H_
