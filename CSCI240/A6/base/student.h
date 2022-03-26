#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <iostream>
#include <string>
#include "address.h"
#include "date.h"

class Student{                                          //begin class definition
  private:
    std::string firstName;
    std::string lastName;
    Address * studentAddr;                              //class methods
    Date * birthDate;
    Date * graduationDate;
    float gpa;
    int creditHours; 

  public:
    Student();                                          //constructors
    Student(std::string firstName, std::string lastName, Address * studentAddr, Date * birthDate, Date * graduationDate, float gpa, int creditHours); 
    ~Student();
    
    std::string getFirstName(); 
    void setFirstName(std::string firstName);
    
    std::string getLastName();
    void setLastName(std::string lastName);              //class methods
    
    Address getStudentAddr();
    void setStudentAddr(Address * studentAddr);
    
    Date getBirthDate();

    void setBirthDate(Date * birthDate);
    
    Date getGraduationDate();
    void setGraduationDate(Date * graduationDate);
    
    float getGPA();
    void setGPA(float gpa);
    
    int getCreditHours();
    void setCreditHours(int creditHours);

    std::string printStudent();

    static void fullReport(Student * students[]);
    static void shortReport(Student * students[]);        //static methods
    static void alphaReport(Student * students[]);
};                                                        //end class definition
#endif
