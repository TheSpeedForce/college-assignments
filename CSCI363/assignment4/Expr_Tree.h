//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_TREE_H_
#define _EXPR_TREE_H_

#include <iostream>
#include <sstream>
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

/**
 * @class Expr_Tree
 *
 * Class to create expression tree. 
 */
class Expr_Tree {
public:

    /// Friend with class Expr_Tree_Builder to allow use of private members
    friend class Expr_Tree_Builder;

    /// Default Constructor
    Expr_Tree (void);

    /**
     * Copy constructor.
     *
     * @param[in]      tree        the tree to copy
     */
    Expr_Tree (Expr_Tree &tree);

    /// Destructor
    ~Expr_Tree (void);

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Expr_Tree& operator = (const Expr_Tree & rhs);

    /// Evaluate the tree using visitor pattern.
    int evaluate (void);

    

private:
    /// The root node of tree
    Expr_Node * root_;

    /// Expr Tree for evaluation
    Eval_Expr_Tree eval_expr_tree_;

};

// Include source file since template file
#include "Expr_Tree.cpp"

#endif //_EXPR_TREE_H_
