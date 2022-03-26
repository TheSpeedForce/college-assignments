// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & stack)    
: stack_ (stack)
{} 

// destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void) 
{}

// create new number
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num) 
{
    return new Number_Command (this->stack_, num);
}

// create new add op
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
    return new Add_Command (this->stack_); 
}

// create new subtract op
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
    return new Subtract_Command (this->stack_);
}

// create new divide op
Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
    return new Divide_Command (this->stack_);
}

// create new muliply op
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{   
    return new Multiply_Command (this->stack_); 
}

// create new mod op
Mod_Command * Stack_Expr_Command_Factory::create_mod_command (void) 
{
   return new Mod_Command (this->stack_);
}


