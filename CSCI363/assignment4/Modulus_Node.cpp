// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
// 
Modulus_Node::Modulus_Node (void)
: precedence_ (2)
{}

//
// Destructor
//
Modulus_Node::~Modulus_Node (void) 
{}

//
// Accept visitor node
//
void Modulus_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Modulus_Node (*this);
}

//
// Evaluate Operation
//
int Modulus_Node::eval (void)
{   
    // get right node to check if zero
    int right = this->right_->eval ();

    // evaluate if right node not zero
    if (right != 0)
    {
        return (this->left_->eval () % this->right_->eval ());
    }

    // Else print error by zero statement
    else
    {
        std::cout << "Modulus by zero not allowed";
        return 0;
    }
}

//
// Return operator precedence
//
int Modulus_Node::get_precedence (void) const
{
    return precedence_;
}
