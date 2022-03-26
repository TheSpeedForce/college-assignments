//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _BINARY_EXPR_NODE_H
#define _BINARY_EXPR_NODE_H

// Inherits from Expr_Node
#include "Expr_Node.h"

/**
 * @class Binary_Expr_Node
 *
 * Create node for operators for in the evaluation tree.
 */
class Binary_Expr_Node : public Expr_Node {
public:
    /// Declaring friend classes to allow use of protected members
    friend class Expr_Tree;
    friend class Eval_Expr_Tree;

    /// Default Constructor
    Binary_Expr_Node (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       left            left node
     * @param[in]       right           right node
     */
    Binary_Expr_Node (Expr_Node *left, Expr_Node *right);

    /// Destructor
    virtual ~Binary_Expr_Node (void);
    
    /**
     * Retrieve the the left node. Pure virtual method.
     *
     * @return          The left node
     */
    virtual Expr_Node*& get_left_node (void);

    /**
     * Set the the left node. Pure virtual method.
     *
     * @param[in]       Node                The node to set
     */
    virtual Expr_Node*& set_left_node (Expr_Node &Node);

    /**
     * Retrieve the the right node. Pure virtual method.
     *
     * @return          The right node
     */
    virtual Expr_Node*& get_right_node (void);

    /**
     * Set the the right node.
     *
     * @param[in]       Node                The node to set
     */    
    virtual Expr_Node*& set_right_node (Expr_Node &Node);

    /// Function to traverse a tree for evaluation.   
    virtual int eval (void);

    /**
     * Retrieve the precedence of node. Pure virtual method.
     *
     * @return          predecence_
     */
    virtual int get_precedence (void) const = 0;

  
protected:
    /// Left node
    Expr_Node * left_;

    /// Right Node
    Expr_Node * right_;    
};

// include source file since template file
#include "Binary_Expr_Node.cpp" 

#endif // _Binary_EXPR_NODE_H
