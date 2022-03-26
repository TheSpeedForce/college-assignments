// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// constructor
//
Expr_Node_Visitor::Expr_Node_Visitor (void)
{}

//
// destructor
//
Expr_Node_Visitor::~Expr_Node_Visitor (void) 
{}

//
// Node visitor method for number
//
void Expr_Node_Visitor::Visit_Number_Node (const Number_Node & node) 
{}

//
// Node visitor method for addition
//
void Expr_Node_Visitor::Visit_Addition_Node (const Addition_Node & node) 
{}

//
// Node visitor method for subtraction
//
void Expr_Node_Visitor::Visit_Subtraction_Node (const Subtraction_Node & node) 
{}

//
// Node visitor method for multiplication
//
void Expr_Node_Visitor::Visit_Multiplication_Node (const Multiplication_Node & node) 
{}

//
// Node visitor method for division
//
void Expr_Node_Visitor::Visit_Division_Node (const Division_Node & node) 
{}

//
// Node visitor method for modulus
//
void Expr_Node_Visitor::Visit_Modulus_Node (const Modulus_Node & node) 
{}