// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
//
Binary_Expr_Node::Binary_Expr_Node (void)
: left_(0),
  right_(0)
{}

//
// Copy constructor
//
Binary_Expr_Node::Binary_Expr_Node (Expr_Node *left, Expr_Node *right)
: left_(left),
  right_(right)
{}

//
// Destructor
//
Binary_Expr_Node::~Binary_Expr_Node (void) 
{}

//
// Get left node
//
Expr_Node*& Binary_Expr_Node::get_left_node (void) 
{
    return this->left_;
}

//
// Set left node
//
Expr_Node*& Binary_Expr_Node::set_left_node (Expr_Node &node) 
{
    this->left_ = &node;
}

//
// Get right node
//
Expr_Node*& Binary_Expr_Node::get_right_node (void) 
{
    return this->right_;
}


//
// Set right node
//
Expr_Node*& Binary_Expr_Node::set_right_node (Expr_Node &node) 
{
    this->right_ = &node;
}

//
// Eval Method
//
int Binary_Expr_Node::eval (void) 
{}
