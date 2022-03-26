//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

// Inherits from Expr_Node
#include "Expr_Node.h"

/**
 * @class Number_Node
 *
 * Create node for number for in the evaluation tree.
 */
class Number_Node : public Expr_Node {
public:

    /**
     * Initializing constructor.
     *
     * @param[in]      num           the number
     */
    Number_Node (int num);

    /// Destructor
    virtual ~Number_Node (void);

    /**
     * Virtual method to accept a visitor node to visit the given node in
     * tree.
     *
     * @param[in]       v                     Expr_Node_Visitor
     */  
    virtual void accept (Expr_Node_Visitor & v);

    /// Virtual method to evaluate operation on left and right nodes. 
    virtual int eval (void);

    /**
     * Retrieve the precedence of operator.
     *
     * @return          predecence_
     */
    virtual int get_precedence (void) const;

    /** The following methods are programmed for the sole purpose
     *  of overriding methods from Expr_Node
     * 
     * 
     */
    
    virtual Expr_Node * & get_left_node (void){}

    virtual Expr_Node * & set_left_node (Expr_Node & Node){}

    virtual Expr_Node * & get_right_node (void){}

    virtual Expr_Node * & set_right_node (Expr_Node & Node){}


private:   

    /// The number for node
    int number_;

    /// Precedence of the node
    int precedence_;
    
};

// include source file since template file
#include "Number_Node.cpp" 

#endif // _NUMBER_NODE_H_
