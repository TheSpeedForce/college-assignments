#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "student.h"
#include "address.h"
#include "date.h"

#define SIZE 50

Student::Student(){                                                      //default constructor
  Student::firstName = "";
  Student::lastName = "";
  Student::studentAddr = new Address();
  Student::birthDate = new Date();
  Student::graduationDate = new Date();
  Student::gpa = 0;
  Student::creditHours = 0;
}

Student::Student(std::string firstName, std::string lastName, Address * studentAddr, Date * birthDate, Date * graduationDate, float gpa, int creditHours){
  Student::firstName = firstName;
  Student::lastName = lastName;

  Student::studentAddr = new Address();
  Student::studentAddr -> setAddrLine1(studentAddr -> getAddrLine1());
  Student::studentAddr -> setAddrLine2(studentAddr->getAddrLine2());
  Student::studentAddr -> setCity(studentAddr->getCity());
  Student::studentAddr -> setState(studentAddr->getState());                    
  Student::studentAddr -> setZip(studentAddr->getZip());

  Student::birthDate = new Date();
  Student::birthDate -> setMonth(birthDate->getMonth());
  Student::birthDate -> setDay(birthDate->getDay());
  Student::birthDate -> setYear(birthDate->getYear());

  Student::graduationDate = new Date();
  Student::graduationDate -> setMonth(graduationDate->getMonth());
  Student::graduationDate -> setDay(graduationDate->getDay());
  Student::graduationDate -> setYear(graduationDate->getYear());

  Student::gpa = gpa;
  Student::creditHours = creditHours;
}

Student::~Student(){                                                             //deconstructor
  delete Student::studentAddr;
  delete Student::birthDate;                
  delete Student::graduationDate;
}


std::string Student::getFirstName(){                                              //function to get student's first name
  return Student::firstName;
}

void Student::setFirstName(std::string firstName){                                //function to set student's first name
  Student::firstName = firstName; 
}

std::string Student::getLastName(){                                               //function to get student's last name
  return Student::lastName;
}

void Student::setLastName(std::string lastName){                                  //function to set student's last name 
  Student::lastName = lastName;
}

Address Student::getStudentAddr(){                                                //function to get student's addrees
  return *Student::studentAddr;
}

void Student::setStudentAddr(Address* studentAddr){                                //function to set student's address
  Student::studentAddr = new Address();
  Student::studentAddr -> setAddrLine1(studentAddr->getAddrLine1());
  Student::studentAddr -> setAddrLine2(studentAddr->getAddrLine2());               //set address object values
  Student::studentAddr -> setCity(studentAddr->getCity());
  Student::studentAddr -> setState(studentAddr->getState());
  Student::studentAddr -> setZip(studentAddr->getZip());
}


Date Student::getBirthDate(){                                                      //function to get student's birth date
  return *Student::birthDate;
}

void Student::setBirthDate(Date * birthDate){                                      //function to set student's birth date
  Student::birthDate = new Date();
  Student::birthDate -> setMonth(birthDate->getMonth());
  Student::birthDate -> setDay(birthDate->getDay());
  Student::birthDate -> setYear(birthDate->getYear());

}

Date Student::getGraduationDate(){                                                  //function to get student's expected graduation date
  return *Student::graduationDate;
}

void Student::setGraduationDate(Date * graduationDate){                             //function to set student's expected graduation date
  Student::graduationDate = new Date();
  Student::graduationDate -> setMonth(graduationDate->getMonth());
  Student::graduationDate -> setDay(graduationDate->getDay());
  Student::graduationDate -> setYear(graduationDate->getYear());
}

float Student::getGPA(){                                                             //function to get student's gpa
  return Student::gpa;
}

void Student::setGPA(float gpa){                                                     //function to set student's gpa
  Student::gpa = gpa;
}

int Student::getCreditHours(){                                                       //function to get student's completed credit hours
  return Student::creditHours;
}

void Student::setCreditHours(int creditHours){                                       //function to set student's credit hours
  Student::creditHours = creditHours;
}

std::string Student::printStudent(){                                                 //function return student report
  std::string address = Student::studentAddr->printAddress();
  std::string bDate = Student::birthDate->printDate();
  std::string gDate = Student::graduationDate->printDate();
  
  std::stringstream gpaConv;
  gpaConv.clear();
  gpaConv << Student::gpa;                                                           //convert gpa from int to string
  std::string Gpa = gpaConv.str();
  
  std::stringstream converter;
  converter.clear();
  converter << Student::creditHours;                                                 //convert creditHours from into to string
  std::string creditHrs = converter.str();
  
  std::string comma = ",";                    
  std::string studentDetail = Student::lastName + comma + Student::firstName + comma + address + comma + bDate + comma + gDate + comma + Gpa + comma + creditHrs;
  return studentDetail;
}

void Student::fullReport(Student * students[]){                                     //static function  to output full report of students
  std::ofstream outFile;
  outFile.open("fullReport.txt");                                                   //open file
  if (outFile.is_open()){
    for(int i = 0; i < SIZE; i++){
      std::string studentDetail = students[i] -> printStudent();                    //output in file, line by line
      outFile << studentDetail << std::endl;
    }
  outFile.close();                                                                  //close file
  }
}
void Student::shortReport(Student * students[]){                                    //static function to output only names of students
  std::ofstream outFile;
  outFile.open("shortReport.txt");                                                  //open file
  if (outFile.is_open()){
    for (int i = 0; i < SIZE; i++){
      std::string space = " ";
      std::string studentName = (students[i]->getLastName()) + space + (students[i]->getFirstName());
      outFile << studentName << std::endl;                                          //output in file, line by line
    }
  }
  outFile.close();                                                                  //close file
}

void Student::alphaReport(Student * students[]){                                    //static function to print student report alphabetically
  std::ofstream outFile;
  outFile.open("alphaReport.txt");                                                  //open file

  std::string studentsDetails[SIZE];                                                //create array for sorting

  for(int i = 0; i < SIZE; i++){
    std::string studentDetail = students[i] -> printStudent();                      //put string in array
    studentsDetails[i] = studentDetail;
  }

  sort(studentsDetails, studentsDetails+SIZE);                                      //sort array
  
  for(int j = 0; j < SIZE; j++){
    outFile << studentsDetails[j] << std::endl;                                     //ouput in file, line by line
  }
  outFile.close();                                                                  //close file
}
