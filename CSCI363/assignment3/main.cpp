#include <iostream>
#include "helper_functions.cpp"


/**
   * Function to comvert infix string of operations to a postfix array.
   *
   * @param[in]       infix                  the infix string
   * @param[in]       factory                the factory to create commands
   * @param[in]       postfix                the array to store postfix commands in
   * @retval          true                   the infix was valid and postfix was created
   * @retval          false                  the infix was not valid and postfix was not created         
   */ 
bool infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{   
    // create a input stream parser   
    std::istringstream input(infix); 
    
    // current token in string/stream  
    std::string token;   

    // create a command object   
    Expr_Command * cmd = 0;              

    // create a temporary stack for operators
    Stack <Expr_Command *> temp;  

    // create a stack for precedence
    Stack <int> precedence;

    // postfix array index for pushing commands
    int index = 0;

    // loop until end of infix string
    while (!input.eof()) 
    {        
        // read character by character using token
        input >> token; 
        if (token == "")
        {
          return false;
        }
        // check if token is an operator
        if (is_operator(token))
        {
          // get precedence of token

          int token_priority;
          token_priority = get_precedence(token);

          // create commands according to operator
          if (token == "+"){
            cmd = factory.create_add_command();
          }

          else if (token == "-"){
            cmd = factory.create_subtract_command();
          }

          else if (token == "*"){
            cmd = factory.create_multiply_command();
          }

          else if (token == "/"){
            cmd = factory.create_divide_command();
          }

          else if (token == "%"){
            cmd = factory.create_mod_command();
          }

          // check if operator stack is empty
          if (!temp.is_empty())
          {
            // get precedence of the top most operator in stack
            int stack_priority = precedence.top();

            // loop until precedence is lower or matches or stack is not empty.
            while (token_priority <= stack_priority && !temp.is_empty() && temp.top() != NULL)
            {
                // get top most command
                cmd = temp.top();

                // pop top most operator
                temp.pop();

                // pop top most precedence
                precedence.pop();

                // push command to postfix array at index and increase index 
                postfix.set(index++, cmd);

                // check if operator stack is empty or top most is left parenthesis
                if (!temp.is_empty() && temp.top() != NULL)
                { 
                  // get precedence again for loop
                  int stack_priority = precedence.top();
                }
            }
          }
            // push command to operator stack
            temp.push(cmd);

            // push precedence of operator to precedence stack
            precedence.push(token_priority);
        }

        // check for left parenthesis
        else if (token == "(") 
        {
          // push NULL to operator stack as it is not a command
          temp.push(NULL);

          // push 0 precedence.
          precedence.push(0);
        }

        // check for right parenthesis
        else if (token == ")")
        {

          // Pop from stack and push to postfix array until left parenthesis (NULL)
          cmd = temp.top();

          // check if left parenthesis
          while (cmd != NULL)
          {
            
            // pop from operator stack and precedence stack
            temp.pop();
            precedence.pop();

            // push to postfix Array
            postfix.set(index++, cmd);
            
            // get next top most command from operator stack
            cmd = temp.top();
          }
          temp.pop();
          precedence.pop();
        }

        // else its a number, not an operator
        else 
        { 
          try {
          //convert string to int
          int convertedString = std::stoi(token);
          cmd = factory.create_number_command(convertedString);

          // push number command to postfix Array
          postfix.set(index++, cmd);
          }
          catch (...){
            return false;
          }
          
        }
    }

    // Pushing all the left operators from operator stack to postfix array 
    while (!temp.is_empty()) 
    {

      // create empty command
      Expr_Command * cmd = 0;

      // get top most command from operator stack
      cmd = temp.top();
      temp.pop();
      precedence.pop();
     
      // push command to array
      postfix.set(index++, cmd);
    }
    return true;
} 

/**
   * Function to evaluate a postfix expression using an array iterator.
   *
   * @param[in]       postfix                   the postfix array to evaluate  
   */ 
void evaluate_postfix(Array <Expr_Command *> & postfix)
{
    // loop on the iter to execute the commands in the Array
    for (int i = 0; i < postfix.size(); i++){
      postfix.get(i)->execute ();
    }
}

/// main function
int main (int argc, char * argv [])
{   
   
    // get input from STDIN concrete factory
    std::string infix;
    std::cout << "Input Infix Expression: ";
    std::getline(std::cin, infix);

    // loop until input is "QUIT"
    while (infix != "QUIT"){
      
      // calculate infix length to use for resizing postfix array 
      int infix_length = (infix.length() / 2) + 1;

      // create Stack for result 
      Stack <int> result;

      // Declare the concrete factor for creating commands
      Stack_Expr_Command_Factory factory (result);

      // Create the Array for storing postfix commands
      Array <Expr_Command *> postfix;

      // Resize postfix to fit all commands
      postfix.resize(infix_length);

      // invoke infix_to_postfix function
      bool valid = infix_to_postfix (infix, factory, postfix);
      

      // check if infix was valid and postfix was created or not
      if (valid){

        // invoke evaluate postfix function
        evaluate_postfix(postfix);

        // get the final result from stack
        int res = result.top ();

        // output final result
        std::cout << "Final Answer: " << res <<std::endl;
      
      }

      // Output inavlid input if infix is not valid.
      else{

        // check input is close to QUIT.
        if (infix == "Quit" || infix == "quit" || infix == "exit")
        {
          std::cout << "To end program, enter QUIT" << std::endl;
        }

        // Output invalid input message
        else
        {
          std::cout << "Invalid Input. Please try again." << std::endl;
        }
      }

      // Ask for input for next line
      std::cout << "Input Infix Expression: ";
      std::getline(std::cin, infix);
    }

    // Program end message
    std::cout << "Quitting calculator." << std::endl;
    return 0;   // end function
}
