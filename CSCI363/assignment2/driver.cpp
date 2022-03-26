#include "Array_Base.h"
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <stdlib.h>

int main (int argc, char * argv [])
  { 
    // perl F:/"Study Material"/SP21/"CSCI 363"/MPC-master/mwc.pl -type make && 
    //git add . && git commit -m "lazy commit" && git push
    
    //git pull origin master && make clean && make && ./assignment2
    
    // git pull https://paagga@github.iu.edu/paagga/cs36300-spring2021-composition && make clean && make && ./Array
    
    // TODO Add code here to test your Array class.


//------------------FIXED ARRAY -------------

if (0){
    std::cout << "-----------FIXED ARRAY TESTS--------------" << std::endl;
    
    Fixed_Array<char, 6> FA0('l');
    Fixed_Array<int, 5> FA1;
    Fixed_Array<char, 4> FA2;
    Fixed_Array<int, 5> FA3(5);
    Fixed_Array<int, 5> FA4(FA3);
    std::cout << "FA4:" << std::endl;
    FA4.print();
    FA0.print();
    std::cout << FA0.size() << std::endl;
    std::cout << FA0.max_size() << std::endl;
    FA3.print();
    FA3.fill(7);
    FA3.print();
    FA0.fill('8');
    FA0.print();
    char p = FA0.get(2);
    std::cout << p << std::endl;
    FA3.set(3,9);
    FA3.print();
    FA1 = FA3;
    FA1.print();
    //FA3.slice(2);
    //FA3.slice(2,6);

    FA1 = FA3;
    //FA1.print();
  }


// --------------ARRAY TESTS--------------------------------------


if (0){
    std::cout << "-----------ARRAY TESTS--------------" << std::endl;
   
    Array<char> string1;
    Array<char> string2(45);
    Array<char> string3(10, '1');
    Array<char> string8(10,'1');
    Array<int> string9(75, 5);
    char a = string3[2];
    std::cout << a << std::endl;
    string9.print();
    if (string3 == string2)
    {
      std::cout << 1 << std::endl;
    }

    if (!(string3 != string2))
    {
      std::cout << 2 << std::endl;
    }

    string3.fill('8');
    string3.set(1, '5');
    string3.set(5, '6');
    string3.set(8, '6');
    string3.reverse();
    string3.print();
    string3.resize(60);
    size_t fe = string3.size();
    size_t fem = string3.max_size();
    int find = string3.find('6');
    int find2 = string3.find('6',4);
    char cind = string3[8];
    Array<char> string4(string3);
    size_t size = string4.size();
    //size_t size2 = string4->size();
    std::cout << "size" << fem << std::endl;
    std::cout << find2 << std::endl;
    std::cout << cind << std::endl;
    std::cout << size << std::endl;
    
   
    Array <char> string5(8,'g');
    Array <int> num1(5,1);
    num1.print();
    string5.print();
    string5.set(2,'j');
    num1.set(4,5);
    num1.print();
    string1.print();
    string1.fill('r');
    string1.print();
    int b = num1.find(1,2);
  }


// ------------------------------QUEUE TESTS ----------------

if (1){

    std::cout << "-----------QUEUE TESTS--------------" << std::endl;
    Queue <int> que1;
    //int t = que1.dequeue();
    Queue <int> que2;
    Queue <int> que3;
    que1 = que1;
    std::cout << "worked" << std::endl;
    que1.enqueue(2);
    que1.print();
    que1.enqueue(8);
    que1.print();
    que1.enqueue(5);
    que1.print();
    que1.enqueue(7);
    que1.print();

    std::cout << "de" <<std::endl;
    int l = que1.dequeue();
    que1.print();
    int o = que1.dequeue();
    
    std::cout << "l" << l << "o" << o <<std::endl;
    que1.enqueue(5);
    que1.print();
    que1.enqueue(7);
    que1.print();
    
    int e = que1.dequeue();
    std::cout << "e" << e <<std::endl;
    que1.enqueue(5);
    que1.print();
    que1.print();
    que1.clear();
    que1.enqueue(5);
    que1.enqueue(7);
    que1.print();
    que1.clear();
    std::cout << "clear worked" << std::endl;
    //Queue <int> que2(que1);
    que2.enqueue(8);
    que2.print();
    //Queue <int> que3;
    que3 = que2;
    que3.print();
    std::cout << "everything worked" << std::endl;
  }

// ----------------- STACK ------------------------------------------------------------  
if (0){
    std::cout << "-----------STACK TESTS--------------" << std::endl;
    Stack <char> s1;
    s1.print();
    s1.push('h');
    s1.push('g');
    s1.push('i');
    s1.push('t');
    s1.print();
    //s1.print();
    s1.pop();
    s1.print();
    s1.pop();
    s1.print();
    Stack <char> s2(s1);
    std::cout << "worked1" << std::endl;
    char w = s1.top();
    std::cout << "worked2" << std::endl;
    std::cout << w << std::endl;
    std::cout << "worked3"<< std::endl;
    s2.print();
    s1.clear();
    s1.print();
    std::cout << "worked4"<< std::endl;
    s2.push('g');
    s2.print();
    Stack <char> s3;
    s3 = s2;
    std::cout << "worked5"<< std::endl;
    s3.print();
    std::cout << "----stack worked----"<< std::endl;
}
    return 0;
}
