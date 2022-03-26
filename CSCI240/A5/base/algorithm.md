#Parsing and File I/O
##Pawas Aggarwal

**Goals**
Build a program, that reads integers and string from a file and writes it in another file.

**Input**
*Opens* a file, *input.txt* , stores the lines *read* in *currentLine*.

**Output**
*Opens* a new file, *output.txt*, *writes* the desired output  in it.

**Steps** 
 - ***Program Algorithm***
1. *Open* the *input* file and the *output* file.
2. *Initialize* required variables.
3. Check *if* file is open. Continue if *true*. Else give *warning*
4. *Read* till end of the*input* file *line by line*.
5. *Iterate* through 1st line of *integers*. using *while* loop.
6. *Convert* numbers in *string* to *integers* type using *stringstream converter*.
7. *Add*  the numbers and store in *sum* and increment *loop control variable*.
8. *Read*  the next line of *text*.
9. *Write* in the *output* file using *for* loop to write the *text* repeated *sum* number of times.
10. *Reset* value of *sum* to *0* to use for the next lines.
11. *Repeat* steps *3 to 8* until end of file is reached.
12. *Close* files.
