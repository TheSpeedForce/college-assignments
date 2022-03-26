//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

// To accept a visitor node
#include "Expr_Node_Visitor.h"

/**
 * @class Expr_Node
 *
 * Class to create expression node using composite visitor pattern.
 *  
 */
class Expr_Node
{
public:

    /// Default constructor
    Expr_Node (void);

    /// Destructor
    virtual ~Expr_Node (void);

    /**
     * Retrieve the the left node. Pure virtual method.
     *
     * @return          The left node
     */
    virtual Expr_Node * & get_left_node (void) = 0;

    /**
     * Set the the left node. Pure virtual method.
     *
     * @param[in]       Node                The node to set
     */
    virtual Expr_Node * & set_left_node (Expr_Node & Node) = 0;

    /**
     * Retrieve the the right node. Pure virtual method.
     *
     * @return          The right node
     */
    virtual Expr_Node * & get_right_node (void) = 0;

    /**
     * Set the the right node.
     *
     * @param[in]       Node                The node to set
     */
    virtual Expr_Node * & set_right_node (Expr_Node & Node) = 0;

    /**
     * Pure virtual method to accept a visitor node to visit the given node in
     * tree.
     *
     * @param[in]       v                     Expr_Node_Visitor
     */
    virtual void accept (Expr_Node_Visitor & v) = 0; 

    /// Pure virtual function to traverse a tree for evaluation.   
    virtual int eval (void) = 0;

    /**
     * Retrieve the precedence of node. Pure virtual method.
     *
     * @return          predecence_
     */
    virtual int get_precedence (void) const = 0;

};

// include source file since template file
#include "Expr_Node.cpp"

#endif //_EXPR_NODE_H