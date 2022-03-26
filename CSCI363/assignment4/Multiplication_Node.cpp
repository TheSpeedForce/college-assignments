// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
// 
Multiplication_Node::Multiplication_Node (void)
: precedence_ (2)
{}

//
// Destructor
//
Multiplication_Node::~Multiplication_Node (void) 
{}

//
// Accept visitor node
//
void Multiplication_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Multiplication_Node (*this);
}

//
// Evaluate Operation
//
int Multiplication_Node::eval (void)
{   
    return (this->left_->eval () * this->right_->eval ());
}

//
// Return operator precedence
//
int Multiplication_Node::get_precedence (void) const
{
    return precedence_;
}
