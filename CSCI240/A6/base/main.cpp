#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "address.h"
#include "date.h"
#include "student.h"

#define SIZE 50

Student * students[SIZE];                                    //create array of pointer of student objects

int main(){
  for(int i = 0; i < SIZE; i++){
    Student * student = new Student();                      //create new object and put in array
    students[i] = student;
  }

  std::ifstream inFile;
  inFile.open("students.txt");                              //open file for reading
  std::string currentLine;      
  std::stringstream converter;                              //initialize stringstream converter
  if (inFile.is_open()){   
    int i = 0;                                              //initialize sentry variable
    while (!inFile.eof()){         
        getline(inFile, currentLine, ',');                  //read line from file
        if (currentLine != ""){
          
          students[i] -> setLastName(currentLine);
          
          getline(inFile, currentLine, ',');
          
          students[i] -> setFirstName(currentLine);         //set values of properties of student object at i from currentLine 
 
          getline(inFile, currentLine, ',');
          
          std::string addrLine1 = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string addrLine2 = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string city = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string state = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string zip = currentLine;

          Address * studentAddrs = new Address(addrLine1, addrLine2, city, state, zip);
          students[i] -> setStudentAddr(studentAddrs);                    //set value of Address of student object at i by using above variables

          getline(inFile, currentLine, '/');
          
          std::string bMonth = currentLine;

          getline(inFile, currentLine, '/');
          
          std::string bDay = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string bYear = currentLine;

          Date * bDate = new Date(bMonth, bDay, bYear);
          students[i] -> setBirthDate(bDate);                            //set values for dates using above way

          getline(inFile, currentLine, '/');
          
          std::string gMonth = currentLine;

          getline(inFile, currentLine, '/');
          
          std::string gDay = currentLine;

          getline(inFile, currentLine, ',');
          
          std::string gYear = currentLine;

          Date * gDate = new Date(gMonth, gDay, gYear);
          students[i] -> setGraduationDate(gDate);

          getline(inFile, currentLine, ',');
          
          float gpa;
          converter.clear();
          converter.str("");
          converter << currentLine;                                      //convert gpa and credit hours from int to string to store
          converter >> gpa;
          students[i] -> setGPA(gpa);

          getline(inFile, currentLine, '\n');
          
          int creditHours;
          converter.clear();
          converter.str("");
          converter << currentLine;      
          converter >> creditHours;
          students[i] -> setCreditHours(creditHours);
        }
      i++;
    }

  }
  inFile.close();                                                        //close reading file
  Student::fullReport(students);
  Student::shortReport(students);                                        //call report functions to output reports
  Student::alphaReport(students);
}
