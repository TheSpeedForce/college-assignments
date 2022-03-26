//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any helps
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

// Inherits from Expr_Builder
#include "Expr_Builder.h"
#include "Expr_Tree.h"

/**
 * @class Expr_Tree_Builder
 *
 * builds an expr tree for use in Calculator
 */
class Expr_Tree_Builder : public Expr_Builder {
public:

    /// Default Constructor
    Expr_Tree_Builder (void);

    /// Destructor
    virtual ~Expr_Tree_Builder (void);

    void build_tree (Expr_Node &node, Expr_Node * &t);

    virtual void start_expression (void);
    virtual void build_number (int n);
    virtual void build_add_operator (void);
    virtual void build_subtract_operator (void);
    virtual void build_multiply_operator (void);
    virtual void build_divide_operator (void);
    virtual void build_mod_operator (void);
    virtual void build_open_parenthesis (void);
    virtual void build_close_parenthesis (void);
    
    void insert_parenthesis (Expr_Node * &t);
    
    
    Expr_Tree * get_expression (void);

private:
    // The tree to build expression
    Expr_Tree * tree_;
    
    // Temporary tree for parenthesis handling
    Expr_Tree * temp_tree_;    
};

// Include source file since template file
#include "Expr_Tree_Builder.cpp"

#endif //_EXPR_TREE_BUILDER_H_
