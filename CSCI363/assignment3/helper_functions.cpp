#include "Array_Base.h"
#include "Array.h"
#include "Stack.h"
#include "Array_Iterator.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"
#include <sstream>
#include <stdlib.h>

/**
   * Function to check if character in infix is an operator.
   *
   * @param[in]       token                 the token to check
   * @retval          true                  the token is an operator
   * @retval          false                  the token is not an operator         
   */  
bool is_operator (const std::string & token) 
{
    // use OR condition to check for all the five operators.
    if(token == "+" || token == "-" || token == "/" || token == "*" || token == "%")
    {
      return true;
    }
    return false;
}


/**
   * Function to get precedence of an operator for math operation.
   *
   * @param[in]       token                 the token to check
   * @retval          1                     the token is add or subtract
   * @retval          2                     the token is multiply, divide or mod. higher precedence         
   */ 
int get_precedence (const std::string & token) 
{
    // check for add and subtract
    if(token == "+" || token == "-")
    {
      return 1;
    }

    // check for multiple, divide and mod. Return higher precedence
    else if (token == "/" || token == "*" || token == "%")
    {
      return 2;
    }
}

bool is_infix_valid(std::string infix)
{ 
    // bool validity = true;
    // if (infix.length() < 3){
    //   validity = false;
    // }
    // else
    // {
    //   for (int i = 0; i < infix.length()-1; i++)
    //   {
    //     if ((infix[i] == "+")
    //   }
    // }
    // return validity;
}