// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
// 
Subtraction_Node::Subtraction_Node (void)
: precedence_ (1)
{}

//
// Destructor
//
Subtraction_Node::~Subtraction_Node (void) 
{}

//
// Accept visitor node
//
void Subtraction_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Subtraction_Node (*this);
}

//
// Evaluate Operation
//
int Subtraction_Node::eval (void)
{
    return (this->left_->eval () - this->right_->eval ());
}


//
// Return operator precedence
//
int Subtraction_Node::get_precedence (void) const
{
    return precedence_;
}
