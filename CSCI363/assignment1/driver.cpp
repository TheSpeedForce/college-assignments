#include "Array.h"
#include <iostream>
#include <stdlib.h>
int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  
  Array string1();
  Array string2(10);
  Array string3(10, '1');
  string3.fill('9');
  string3.set(1, '8');
  string3.set(5, '5');
  string3.reverse();
  string3.printArray();
  Array string5 (10, '5');
  string5.set(3,'8');
  string5.printArray();
  Array sliced(string5.slice(2,5));
  sliced.printArray();
  string2.reverse();
  string3.resize(15);
  string3.shrink();
  int find = string3.find('2');
  char cind = string3[8];
  Array string4(string3);
  std::cout << cind <<":" << find << std::endl;
 
  return 0;
}
