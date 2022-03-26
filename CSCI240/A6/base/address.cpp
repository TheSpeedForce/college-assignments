#include <iostream>
#include <string>
#include "address.h"

Address::Address(){                                                     //default constructor  
  Address::addrLine1 = "";
  Address::addrLine2 = "";
  Address::city = "";
  Address::state = "";
  Address::zip = "";
}

Address::Address(std::string addrLine1, std::string addrLine2, std::string city, std::string state, std::string zip){
  Address::addrLine1 = addrLine1;                                  
  Address::addrLine2 = addrLine2;
  Address::city = city;
  Address::state = state;
  Address::zip = zip;
}

Address::~Address(){                                                      //deconstructor
  delete this;
}

std::string Address::getAddrLine1(){                                      //function to get address line 1
  return Address::addrLine1;
}

void Address::setAddrLine1(std::string addrLine1){                        //function to set address line 1
  Address::addrLine1 = addrLine1;
}

std::string Address::getAddrLine2(){                                      //function to get address line 2
  return Address::addrLine2;
}

void Address::setAddrLine2(std::string addrLine2){                        //function to set address line 2
  Address::addrLine2 = addrLine2;
}

std::string Address::getCity(){                                           //function to get city
  return Address::city;
}

void Address::setCity(std::string city){                                  //function to set city
  Address::city = city;
}

std::string Address::getState(){                                          //function to get state
  return Address::state;
}

void Address::setState(std::string state){                                //function to set state
  Address::state = state;
}

std::string Address::getZip(){                                            //function to get zip
  return Address::zip;
}

void Address::setZip(std::string zip){                                    //function to set zip
  Address::zip = zip;
}

std::string Address::printAddress(){                                      //function to return complete address
  std::string comma = ",";                                                //create address variable by concatenation
  std::string address = Address::addrLine1 + comma + Address::addrLine2 + comma + Address::city + comma + Address::state + comma + Address::zip;
  return address;
}

