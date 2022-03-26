#include <iostream>
#include <string>
#include "date.h"

Date::Date(){                                     //default constructor
  Date::month = "";
  Date::day = "";
  Date::year = "";
}

Date::Date(std::string month, std::string day, std::string year){
  Date::month = month;
  Date::day = day;
  Date::year = year;
}


Date::~Date(){                                     //deconstructor
  delete this;
}

std::string Date::getMonth(){                      //function to get month
  return Date::month;
}

void Date::setMonth(std::string month){            //function to set month
  Date::month = month;
}                     

std::string Date::getDay(){                         //function to get day
  return Date::day;
}                 

void Date::setDay(std::string day){                 //function to set day
  Date::day = day; 
} 

std::string Date::getYear(){                        //function to get year
  return Date::year;
}                   

void Date::setYear(std::string year){               //function to set year
  Date::year = year;
}                                          

std::string Date::printDate(){                      //function to return complete date
  std::string slash = "/";
  std::string date = Date::month + slash + Date::day + slash + Date::year;      //create date string by concatenation
  return date;
}
