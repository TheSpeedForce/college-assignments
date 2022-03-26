// shared_exe.cpp
#include "my_shared_lib.h"

// main function
int main (int argc, char * argv [])
{ 
    print_message ("Hello, World!");

    // create greeting object
    Greeting g;

    // call object method
    g.say_message ("Hello, World!");
    return 0;
}