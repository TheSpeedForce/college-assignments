// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// constructor
Add_Command::Add_Command (Stack <int> & s)
: Binary_Op_Command (s)                           // call parent class constructor 
{}


// add two numbers together
int Add_Command::evaluate (int n1, int n2) const
{
    return n2 + n1;                                              
}

// deconstructor
Add_Command::~Add_Command (void) 
{}