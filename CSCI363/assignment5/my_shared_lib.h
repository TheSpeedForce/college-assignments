#include <string>

#include "my_shared_lib_export.h"

MY_SHARED_LIB_Export
void print_message(const std::string & msg);

class MY_SHARED_LIB_Export Greeting
{
    public:
        Greeting (void);
        ~Greeting (void);
        void say_message (const std::string & msg);
};