// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// constructor
Mod_Command::Mod_Command (Stack <int> & s) 
: Binary_Op_Command (s)
{}

// evaluate remainder
int Mod_Command::evaluate (int n1, int n2) const 
{
    return n2 % n1; 
}

// destructor
Mod_Command::~Mod_Command (void) 
{}