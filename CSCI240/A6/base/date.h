#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <iostream>
#include <string>

class Date{                                                           //begin class defintion
  private:
    std::string month;
    std::string day;                                                  //class properties
    std::string year;

  public:
    Date();
    Date(std::string month, std::string day, std::string year);       //constructors
    ~Date();
    std::string getMonth();                                             
    void setMonth(std::string month);                                   	
    std::string getDay();                                             //class methods  
    void setDay(std::string day);                                       
    std::string getYear();                                              
    void setYear(std::string year);                                          
    std::string printDate();                                            
};                                                                    //end class definition
#endif
