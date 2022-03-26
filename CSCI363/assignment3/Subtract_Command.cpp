// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// constructor
Subtract_Command::Subtract_Command (Stack <int> & s)
: Binary_Op_Command (s)
{}

// subtract two numbers
int Subtract_Command::evaluate (int n1, int n2) const
{
    return n2 - n1; 
}

// destructor
Subtract_Command::~Subtract_Command(void)
{}