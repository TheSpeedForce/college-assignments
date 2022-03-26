// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// 
// Constructor
//
Expr_Tree_Builder::Expr_Tree_Builder (void) 
: tree_ (0),
  temp_tree_ (0)
{}

//
// Destructor
//
Expr_Tree_Builder::~Expr_Tree_Builder (void) 
{
    delete this->tree_;
    delete this->temp_tree_;
}

//
// Build Tree
//
void Expr_Tree_Builder::build_tree (Expr_Node &node, Expr_Node *&t) 
{

    // check If t is nullptr 
    if (t == nullptr)
        t = &node;

    // Check precedence of node and t to decide order
    else if (node.get_precedence () <= t->get_precedence ()){
        Expr_Node * temp = t;
        node.set_left_node (*temp);
        t = &node;
    }

    // Else if node precedence higher, then build new tree
    else {
        this->build_tree (node, t->get_right_node ());
    }
}

void Expr_Tree_Builder::start_expression (void) 
{
    this->tree_ = new Expr_Tree ();
}

void Expr_Tree_Builder::build_number (int num) 
{
    Expr_Node * node;
    node = new Number_Node (num);
    this->build_tree (*node, this->tree_->root_);
}


void Expr_Tree_Builder::build_add_operator (void) 
{
    Expr_Node *node;
    node = new Addition_Node ();
    this->build_tree (*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_subtract_operator (void)
{
    Expr_Node *node;
    node = new Subtraction_Node ();
    this->build_tree (*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_multiply_operator (void) 
{
    Expr_Node *node;
    node = new Multiplication_Node ();
    this->build_tree (*node, this->tree_->root_);

}

void Expr_Tree_Builder::build_divide_operator (void) 
{
    Expr_Node *node;
    node = new Division_Node ();
    this->build_tree (*node, this->tree_->root_);

}

void Expr_Tree_Builder::build_mod_operator (void) 
{
    Expr_Node * node;
    node = new Modulus_Node ();
    this->build_tree (*node, this->tree_->root_);
}

void Expr_Tree_Builder::build_open_parenthesis (void) 
{
    // Use a temporary tree for parenthesis
    this->temp_tree_ = new Expr_Tree ();
    this->temp_tree_->root_ = this->tree_->root_;
    this->tree_->root_ = nullptr;
}

void Expr_Tree_Builder::build_close_parenthesis (void) 
{
    this->insert_parenthesis(this->temp_tree_->root_);
    this->temp_tree_->root_ = nullptr;
}



void Expr_Tree_Builder::insert_parenthesis (Expr_Node *&t) 
{
    if (t == nullptr) 
    {
       Expr_Node * node = new Number_Node(this->tree_->root_->eval());
        t = node;
        this->tree_->root_ = this->temp_tree_->root_;
    }
    else
    {
        insert_parenthesis(t->get_right_node());
    }
}

Expr_Tree * Expr_Tree_Builder::get_expression (void)
{
    return this->tree_;
} 
