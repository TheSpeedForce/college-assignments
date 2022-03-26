// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
// 
Addition_Node::Addition_Node (void)
: precedence_ (1)
{}

//
// Destructor
//
Addition_Node::~Addition_Node (void) 
{}

//
// Accept visitor node
//
void Addition_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Addition_Node(*this);
}

//
// Evaluate Operation
//
int Addition_Node::eval (void)
{
    return (this->left_->eval () + this->right_->eval ());
}


//
// Return operator precedence
//
int Addition_Node::get_precedence (void) const
{
    return precedence_;
}
