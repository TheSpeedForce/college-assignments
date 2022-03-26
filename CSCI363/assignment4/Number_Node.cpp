// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
//
Number_Node::Number_Node (int num)
: number_(num),
  precedence_ (0)
{}

//
// Destructor
//
Number_Node::~Number_Node (void) 
{}

//
// Accept visitor node
//
void Number_Node::accept (Expr_Node_Visitor & v)
{
    v.Visit_Number_Node (*this);
}

//
// Evaluate Number node by returning the number
//
int Number_Node::eval (void)
{
    return (this->number_);
}

//
// Get precedence
//
int Number_Node::get_precedence (void) const
{
    return precedence_;
}