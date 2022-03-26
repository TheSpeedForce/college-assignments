//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

// constructor
Binary_Op_Command::Binary_Op_Command (Stack <int> & s) 
: s_ (s)
{} 

void Binary_Op_Command::execute (void) {

    // pop last two numbers from stack to perform binary operation on.
    int n1 = s_.top();
    s_.pop();   
    int n2 = s_.top();
    s_.pop();
    
    // evaluate result
    int result = this->evaluate (n1, n2);     
    
    // push result into stack
    s_.push (result); 
}

Binary_Op_Command::~Binary_Op_Command(void) 
{   
    // delete the stack
    delete & s_;
}