// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


// constructor
Divide_Command::Divide_Command (Stack <int> & s)
: Binary_Op_Command (s)
{}

// divide two numbers
int Divide_Command::evaluate (int n1, int n2) const
{
    // condition when denominator (n2) is zero.
    if (n2 != 0)
    {
        return n2 / n1; 
    } 
    
    else 
    {
        // print exception here
        std::cout<<"Division by Zero not allowed.";
    }
}

// destructor
Divide_Command::~Divide_Command (void)
{}