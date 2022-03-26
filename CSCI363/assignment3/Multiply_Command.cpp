// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// constructor
Multiply_Command::Multiply_Command (Stack <int> & s)
: Binary_Op_Command (s)
{}

// multiply two numbers
int Multiply_Command::evaluate (int n1, int n2) const
{
    return n2 * n1; 
}

// destructor
Multiply_Command::~Multiply_Command(void) 
{}

