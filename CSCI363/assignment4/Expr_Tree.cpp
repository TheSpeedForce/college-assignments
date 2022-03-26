// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Tree.h"

//
// Constructor
//
Expr_Tree::Expr_Tree (void)
: root_ (nullptr)
{}

// 
// Copy Constructor
Expr_Tree::Expr_Tree (Expr_Tree &tree)
: root_ (tree.root_)
{}

// 
// Destructor
// 
Expr_Tree::~Expr_Tree (void)
{
    delete this->root_;
}

//
// Evaluate method
//
int Expr_Tree::evaluate (void)
{   
    // Accept a tree to put at root.
    this->root_->accept (this->eval_expr_tree_);

    // Output the result of the tree.
    std::cout << "Final Answer: " << this->eval_expr_tree_.result () << std::endl;
}

//
// assignment operator
//
const Expr_Tree & Expr_Tree::operator = (const Expr_Tree & rhs) 
{   
    // self comparison check
    if (this == &rhs)
    {
        return *this;
    }

    // set rhs to this root
    delete this->root_;
    this->root_ = rhs.root_;
    return *this;
}