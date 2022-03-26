//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

// Inlclude Tree and Node header files
#include "Expr_Tree.h"
#include "Expr_Node.h"

// Include operation nodes
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"


/**
 * @class Expr_Builder
 *
 * Class to build operation in the tree using builder pattern
 */
class Expr_Builder {
public:

    /// Default Constructor
    Expr_Builder (void);

    /// Destructor
    ~Expr_Builder (void);


    /// Method to start expression
    virtual void start_expression (void);


    /// Pure virtual methods to build operation nodes in the tree
    virtual void build_number (int n) = 0;
    virtual void build_add_operator (void) = 0;
    virtual void build_subtract_operator (void) = 0;
    virtual void build_multiply_operator (void) = 0;
    virtual void build_divide_operator (void) = 0;
    
    /// Pure virtual methods to handle parenthesis in the expression
    virtual void build_open_parenthesis (void) = 0;
    virtual void build_close_parenthesis (void) = 0;
    
    /// Pure virtual method to get the current expression.
    virtual Expr_Tree * get_expression (void) = 0;
};

// Include source file since template file
#include "Expr_Builder.cpp"

#endif //_EXPR_BUILDER_H_
