//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

// Inherits from Expr_Node_Visitor
#include "Expr_Node_Visitor.h"

// Include operation nodes
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"

/**
 * @class Eval_Expr_Tree
 *
 * Class to evaluate the expression tree by visiting nodes. 
 */
class Eval_Expr_Tree : public Expr_Node_Visitor {
public:

    /// Default Constructor
    Eval_Expr_Tree (void);

    /// Destructor
    virtual ~Eval_Expr_Tree (void);

     /**
     * Virtual methods to visit concrete nodes in the tree.
     *
     * @param[in]       node                     the node
     */ 
    virtual void Visit_Number_Node (Number_Node & node);
    virtual void Visit_Addition_Node (const Addition_Node & node);
    virtual void Visit_Subtraction_Node (const Subtraction_Node & node);
    virtual void Visit_Multiplication_Node (const Multiplication_Node & node);
    virtual void Visit_Division_Node (const Division_Node & node);
    virtual void Visit_Modulus_Node (const Modulus_Node & node);

    /**
     * Retrieve the final result after evaluating the expression.
     *
     * @return          final answer
     */ 
    int result (void) const;

private:

    /// Int variable to store result
    int result_;

};

// Include source file since template file
#include "Eval_Expr_Tree.cpp"

#endif //_EVAL_EXPR_TREE_H_
