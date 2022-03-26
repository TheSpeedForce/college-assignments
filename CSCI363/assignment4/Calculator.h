//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <iostream>
#include <sstream>
#include "Expr_Tree_Builder.h"
#include "Expr_Tree.h"

/**
 * @class Calculator
 *
 * Create calculator for expression.
 */
class Calculator {
public:
    /// Default Constructor
    Calculator (void);

    /// Destructor
    ~Calculator (void);

    /**
     * Parse infix expression and build nodes for each 
     * character and evaluate expression 
     *
     * @retval          true            expression is valid
     * @retval          false           expression is not valid
     */
    bool parse_expr (const std::string & infix);

private:
    /// Builder for nodes
    Expr_Tree_Builder builder_;

    /// Tree for expression
    Expr_Tree *tree_;

    /// Temporary tree for expression inside parenthesis
    Expr_Tree *tree_two_;
};

// Include source file since template file
#include "Calculator.cpp"

#endif //_CALCULATOR_H
