   // -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"

/**
 * @class Number_Command
 *
 * Command class for numbers in expression, inherits Expr_Command.
 * 
 */

class Number_Command : public Expr_Command 
{
public:   
    
    // constructor
    Number_Command (Stack <int> &s, int num); 
    
    // execute method
    void execute (void);

    // destructor
    ~Number_Command (void);

private:   

    //create stack object
    Stack <int> & s_;   
    int n_; 
};

// include source file since template file
#include "Number_Command.cpp"

#endif  // !defined _NUM_COMMAND_H_