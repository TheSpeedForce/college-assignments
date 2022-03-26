#include <iostream>
#include "Calculator.h"

/// main function
int main (int argc, char * argv [])
{   
   
    // get input from STDIN concrete factory
    std::string infix;
    std::cout << "Input Infix Expression: ";
    std::getline(std::cin, infix);

    // loop until input is "QUIT"
    while (infix != "QUIT"){
      
      // Create Calculator object  
      Calculator calculator;

      // Parse expression and evaluate if valid
      bool valid = calculator.parse_expr(infix);

      // Output error message if invalid
      if (!valid)
      {
        std::cout << "Invalid Expression, try again" << std::endl;
      }

      // Ask for input for next line
      std::cout << "Input Infix Expression: ";
      std::getline(std::cin, infix);
    }

    // Program end message
    std::cout << "Quitting calculator." << std::endl;
    return 0;   // end function
}


// git merge to master for final submission


// perl F:/"Study Material"/SP21/"CSCI 363"/MPC-master/mwc.pl -type make

// git add . && git commit -m "lazy commit" && git push origin master

// git config --global credential.helper 'cache --timeout=3600'
    
// git pull origin master && make clean && make && ./assignment4

