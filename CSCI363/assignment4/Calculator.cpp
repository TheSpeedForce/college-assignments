// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//
// Constructor
//
Calculator::Calculator (void)
{}


//
// Deconstructor
//
Calculator::~Calculator (void)
{}

//
// parse_expr function
//
bool Calculator::parse_expr (const std::string &infix) 
{
    // Create a input stream parser
    std::istringstream input (infix); 

    // Create token for stream
    std::string token;                
    
    // Start a new expression
    builder_.start_expression ();        

    // Run until end of expression    
    while (!input.eof ()) {

        // Pass token to input
        input >> token;

        // Build node for addition
        if (token == "+")
        {
            this->builder_.build_add_operator ();
        }

        // Build node for subtraction
        else if (token == "-")
        {
            this->builder_.build_subtract_operator ();
        }
        
        // Build node for multiplication
        else if (token == "*")
        {
            this->builder_.build_multiply_operator ();
        }
        
        // Build node for division
        else if (token == "/")
        {
            this->builder_.build_divide_operator ();
        }
        
        // Build node for modulus
        else if (token == "%")
        {       
            this->builder_.build_mod_operator ();
        }
        
        // Build node for right parenthesis
        else if (token == "(")
        {
            this->builder_.build_open_parenthesis ();
        }

        
        // Build node for left parenthesis
        else if (token == ")")
        {
            this->builder_.build_close_parenthesis ();
        }

        // Build node for number
        else 
        {   
            // convert str to int
            int num = std::stoi (token);
            this->builder_.build_number (num);
        }
    }


    // Get the parsed tree
    this->tree_ = builder_.get_expression ();

    // Evaluate tree
    this->tree_->evaluate ();
    
    return true;
}

