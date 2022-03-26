// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
// 
Division_Node::Division_Node (void)
: precedence_ (2)
{}

//
// Destructor
//
Division_Node::~Division_Node (void) 
{}

//
// Accept visitor node
//
void Division_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Division_Node (*this);
}

//
// Evaluate Operation
//
int Division_Node::eval (void)
{   
    // get right node to check if zero
    int right = this->right_->eval ();

    // evaluate if right node not zero
    if (right != 0)
    {
        return (this->left_->eval () / this->right_->eval ());
    }

    // Else print error by zero statement
    else
    {
        std::cout << "Division by zero not allowed";
        return 0;
    }
}

//
// Return operator precedence
//
int Division_Node::get_precedence (void) const
{
    return precedence_;
}
