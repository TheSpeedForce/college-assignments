//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

// Inherits from Binary_Expr_Node
#include "Binary_Expr_Node.h"

/**
 * @class Modulus_Node
 *
 * Create node for modulus in the evaluation tree.
 */
class Modulus_Node : public Binary_Expr_Node {
public:

    /// Default constructor
    Modulus_Node (void);

    /// Destructor
    virtual ~Modulus_Node (void);
        
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

private:

    /// Precedence of the operator
    int precedence_;
};

// include source file since template file
#include "Modulus_Node.cpp" 

#endif // _MODULUS_NODE_H_
