//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================


#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

#include <iostream>

// Forward declarations
class Number_Node;
class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;


/**
 * @class Expr_Node_Visitor
 *
 * Class to visit all nodes in the tree. 
 */
class Expr_Node_Visitor {
public:
    /// Default Constructor
    Expr_Node_Visitor (void);

    /// Destructor
    virtual ~Expr_Node_Visitor (void);

    /**
     * Virtual methods to visit concrete nodes in the tree.
     *
     * @param[in]       node                     the node
     */ 
    virtual void Visit_Number_Node (const Number_Node & node);
    virtual void Visit_Addition_Node(const Addition_Node & node);
    virtual void Visit_Subtraction_Node (const Subtraction_Node & node);
    virtual void Visit_Multiplication_Node (const Multiplication_Node & node);
    virtual void Visit_Division_Node (const Division_Node & node);
    virtual void Visit_Modulus_Node (const Modulus_Node & node);
};

// include source file since template file
#include "Expr_Node_Visitor.cpp"

#endif //_EXPR_NODE_VISITOR_H_
