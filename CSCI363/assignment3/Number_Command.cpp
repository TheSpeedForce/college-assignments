// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

// constructor
Number_Command::Number_Command (Stack <int> & s, int num)
: s_ (s),
  n_ (num)
{}  
    
// push the number on the stack
void Number_Command::execute (void)
{     
    s_.push (n_);   
}

// destructor
Number_Command::~Number_Command(void) 
{}

