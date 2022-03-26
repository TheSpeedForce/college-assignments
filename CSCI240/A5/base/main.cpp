#include <fstream>
#include <iostream>
#include <sstream>

int main(){                                       //main function
  
  std::ifstream inFile;
  std::ofstream outFile;                          //create required file objets
  inFile.open("input.txt");                       //open file for reading
  outFile.open("output.txt");                     //open file for output
  
  std::string currentLine;                        //initialize string variable
  std::stringstream converter;                    //initialize string to integer conveter
  int sum = 0;                                    
  int check = 0;                                  //initalize required variables

         
  if (inFile.is_open()){                          //check if reading file is open
    while (getline(inFile, currentLine)){         //run while loop till end of reading file
	int i = 0;                           
	while (currentLine[i]){                   //run loop till end of line
  		int number;                 
                converter.clear();
  		converter.str("");
		converter << currentLine[i];      //use stringsteam converter to convert string character to integer type
                converter >> number;
		sum = sum + number;               //add number to sum
		i++;                              //increment iterator value
	}	
	getline(inFile, currentLine);             //read next string line in file

	for (int j = 0; j < sum; j++){           
           outFile << currentLine << ",";         //write the desired output in file using for loop
	}
	outFile << std::endl;

	sum = 0;                                  //reset sum to 0
      }
  outFile.close();
  inFile.close();                                 //close files
  }
  else{
    std::cout<<"Error opening file";              //give information if file cannot open
  }
  return 0; 
}                                                 //end main function
