// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
//
Eval_Expr_Tree::Eval_Expr_Tree (void)
: result_ (0)
{}

//
// DestructOr
//
Eval_Expr_Tree::~Eval_Expr_Tree (void) 
{}

// 
// Visit Number Node
//
void Eval_Expr_Tree::Visit_Number_Node (Number_Node & node) 
{
    // get number
    this->result_ = node.eval ();
}

//
// Visit Addition Node
//
void Eval_Expr_Tree::Visit_Addition_Node (const Addition_Node & node) 
{
    // get result by adding left and right nodes
    this->result_ = node.left_->eval () + node.right_->eval ();
}

//
// Visit Subtraction Node
//
void Eval_Expr_Tree::Visit_Subtraction_Node (const Subtraction_Node & node) 
{
    // get result by subtracting left and right nodes
    this->result_ = node.left_->eval () - node.right_->eval ();
}

//
// Visit Multiplication Node
//
void Eval_Expr_Tree::Visit_Multiplication_Node (const Multiplication_Node & node) 
{
    // get result by multiplying left and right nodes
    this->result_ = node.left_->eval () * node.right_->eval ();
}

//
// Visit Division Node
//
void Eval_Expr_Tree::Visit_Division_Node (const Division_Node & node) 
{   
    // check if right node is zero
    int right = node.right_->eval ();

    // calculate if not zero
    if (right != 0)
    {
        // get result by dividing left and right nodes
        this->result_ = node.left_->eval () / node.right_->eval ();
    }
    
    // output error message if right node is zero
    else
    {
        std::cout << "Division by zero not allowed." << std::endl;
    }
    
}

//
// Visit Modulus Node
//
void Eval_Expr_Tree::Visit_Modulus_Node (const Modulus_Node & node) 
{   
    // check if right node is zero
    int right = node.right_->eval ();

    // calculate if not zero
    if (right != 0)
    {
        // get result by dividing left and right nodes
        this->result_ = node.left_->eval () % node.right_->eval ();
    }

    // output error message if right node is zero
    else
    {
        std::cout << "Division by zero not allowed." << std::endl;
    }
}


// Result method
int Eval_Expr_Tree::result (void)  const
{
    // return result
    return this->result_;
}