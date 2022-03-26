#A heap of students Algorithm
##Pawas Aggarwal

**Goals**
Build a normalized student record system. Create a class to represent student data.

**Input**
*Opens* a file, *students.txt* , stores the lines *read* in *currentLine*.

**Output**
*Opens*  new files, *fullReport.txt*, *shortReport.txt*, *alphaReport.txt* *writes* the desired output  in it.


**Steps** 
 - **Program Algorithm**
1. Initialize *array* of *Student* object pointers of *SIZE*. 
2. Create new Student objects and put in array.
3. Open file for reading.
4. Read till end of file
5. Put values in properties of the student object array from the currentLine.
6. Convert gpa and creditHours from string to int to store in Student object.
7. Close file after reading is complete.
8. Call Student functions to output reports.

