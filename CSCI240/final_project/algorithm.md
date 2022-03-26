#WriterSpot Algorithm
##Pawas Aggarwal
**Goals**

Create a program for user to write anything and see what others wrote.

**Input**

Opens a file, Writers.dat , stores the data in a vector writers.

Opens a file, stories.dat , stores the data in a vector stories.

**Output**

Opens the file Writers.dat, outputs the vector writers in it.

**Steps** 

 - ***Program Algorithm***
 
1. *Open* the *input* file*Writers.dat* , reads data into vectors *writers*.
2. Show *mainMenu()*.
3. If *choice* is sign up, ask for *username* and *password* and create if doesn’t exist already.
4. If *choice* is sign in, ask for *username* and *password*. Check for *login* credentials. Open *writerMenu* if *writer*. Show *adminMenu* if credentials match to admin.
5. If *choice* is exit, *confirm* exit and end program if *yes*.

- ***Entry.java***:
	 *Entry(String userEntry, boolean isPublic)*:
	 *construct* object.

	*getEntry()*:
	return *object.entry*  as String.

	*setEntry(String userEntry)*:
	 set *object.entry* to userEntry.

	*getPublicStatus()*:
	return *object.isPublic* as boolean.

	*setPublicStatus(boolean isPublic)*:
	set *object.isPublic* to *isPublic*

- **Writer.java***:
	*Writer(String username, String password):
	*construct* object.

	*getUsername()*:
	return *object.username* as String.

	*setUsername(String username)*:
	set *object.username*  to username.

	*getPassword()*:
	return *object.password* as String.

	*setPassword(String password)*:
	set *object.password* to *password*.

	*getEntries()*:
	return *object.entries* as Vector.
	
	*newEntry(String userEntry, boolean isPublic)*:
	
	a. Check if *userEntry* already exists.
	
	b. if *true*, print *already exists*.
	
	c. if *false*, make new *Entry* object and add to *object.entries*.
	

	*delEntry()*:
	
	 a. if size of *entries* is 0, print *no entries*.
	 
	 b. else, call *object.listEntries* to print *entries*.
	 
	 c. Ask *entry* number to delete*
	 
	 d. Check if input is valid, delete if *true*.
	 
	 e. If *invalid input* print invalid input.

	*editEntry()*:
	
	a. if size of *entries* is 0, print *no entries*.
	
	b. else, call *object.listEntries* to print *entries*.
	
	c. Ask *entry* number to delete*
	
	d. Check if input is valid, ask for *editedEntry* if *true*., set *object.entry* to *editedEntry*.
	
	e. If *invalid input* print invalid input.
	
	*listEntries()*:
	
	a. if size of *entries* is 0, print *no entries*.
	
	b. run *for*  loop to traverse through *object.entries*
	
	c. Get *entry* and *status* from each object in *object.entries*.
	
	d. Print *entry* and *status*.
	
- ***Menu.java***:

	Open *Writers.dat* and read vector and store in *writers*.
	
	call *mainMenu* to run program.
