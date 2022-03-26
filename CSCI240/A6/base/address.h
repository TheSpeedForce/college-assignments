#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

#include <iostream>
#include <string>

class Address{                                          //begin class defintion
  private:
    std::string addrLine1;
    std::string addrLine2;                              //class properties
    std::string city;
    std::string state;
    std::string zip; 

  public:
    Address();                                          //class constructors
    Address(std::string addrLine1, std::string addrLine2, std::string city, std::string state, std::string zip);
    ~Address();
    std::string getAddrLine1();
    void setAddrLine1(std::string addrLine1);           //class methods
    std::string getAddrLine2();
    void setAddrLine2(std::string addrLine2);
    std::string getCity();
    void setCity(std::string city);
    std::string getState();
    void setState(std::string state);
    std::string getZip();
    void setZip(std::string zip);
    std::string printAddress();
};                                                       //end class definitions
#endif
