import java.io.*;
import java.util.*;

public class Menu extends Writer implements Serializable {                                     //class definition begins
	
	public static void main(String[] args){
		Menu menu = new Menu();                                              //create class object
		Vector writers = null;
    try {
      FileInputStream writersFile = new FileInputStream("Writers.dat"); //create file object for input
      ObjectInputStream inputFile = new ObjectInputStream(writersFile);
      writers = (Vector)inputFile.readObject();
      inputFile.close();                                                            //close input file      
    }
    catch (IOException ex){
	  	writers = new Vector();
		}
    catch (ClassNotFoundException ex){                      				      //check for errors
			System.out.println("ClassNotFoundException occured");
		}
		menu.mainMenu(writers);
  }
  public void saveData(Vector writers){
    try{
      FileOutputStream writersFile = new FileOutputStream("Writers.dat");
      ObjectOutputStream outputFile = new ObjectOutputStream(writersFile);									
      outputFile.writeObject(writers);                                                          //save and close output file
      writersFile.close();
      outputFile.close();
    }
    catch(Exception e){
      System.out.println("IOException occured");
    }
  }

  public void mainMenu(Vector writers){
    System.out.println();
    System.out.println("--------------------------------------------------");
    System.out.println("Welcome to WriterSpot. A place for people who want to write and share with others.");
    System.out.println("Please choose from following options:");
		System.out.println("1. Sign Up");
		System.out.println("2. Sign In");
		System.out.println("3. Exit");
    System.out.print("Choice: ");


		Scanner mainChoice = new Scanner(System.in);
		int choice = mainChoice.nextInt();

    switch(choice){
      case 1:
        System.out.println();
        System.out.println("--------------------------------------------------");
        System.out.println("Sign Up");
        System.out.print("Enter a Username: ");
    		Scanner usrnmIn = new Scanner(System.in);
		    String username = usrnmIn.nextLine();                                    //ask fot logi credentials
        boolean keepGoing = true;
        while (keepGoing){
          boolean writerExists = false;
          for(int i = 0; i < writers.size(); i++){
            Writer wrtr = new Writer();
            wrtr = (Writer)writers.get(i);
            String usrn = wrtr.getUsername();
            if ((username).equals(usrn)){
              System.out.println("Username already exists, try again.");
              i = writers.size();
              writerExists = true;
              keepGoing = false;
              this.mainMenu(writers);  
            }
          }
          if (writerExists == false){
            System.out.print("Enter a password: ");
            Scanner pswdIn = new Scanner(System.in);
		        String password = pswdIn.nextLine();
            Writer newWriter = new Writer(username, password);
            writers.add(newWriter);
            System.out.println("Writer created successfully. You will have to put login credentials to sign in.");
            this.loginMenu(writers);   
            keepGoing = false;
          }
        }
        break;

      case 2:
        this.loginMenu(writers);
        break;
      case 3:
        System.out.println("\n");
        System.out.println("--------------------------------------------------");
        System.out.print("Are you sure you want to exit (Y/N): ");
        Scanner exitChoice = new Scanner(System.in);
        String exitConfirm = exitChoice.nextLine();
        if (exitConfirm.equals("yes") || exitConfirm.equals("YES") || exitConfirm.equals("y") || exitConfirm.equals("Y")){
          System.out.println("Exiting now");
          System.exit(0);
        }
        else{
          if(exitConfirm.equals("no") || exitConfirm.equals("NO") || exitConfirm.equals("n") || exitConfirm.equals("N")){
            System.out.println("Taking you back");
          }
          else{
          System.out.println("Invalid Choice, please try again.");
          }
          this.mainMenu(writers);
        }
        break;
      default:
        System.out.println("Invalid choice, try again.");
        this.mainMenu(writers);  
    }

  }
	
  public void loginMenu(Vector writers){							      //function for loggin in
    System.out.println("--------------------------------------------------");
		System.out.println("Welcome to the login section. Please enter following");
		System.out.print("Username: ");
		Scanner usrnmIn = new Scanner(System.in);
		String username = usrnmIn.nextLine();                                         
    

		if (username.equals("admin")){ 
      System.out.print("Password for admin: ");
      Scanner pswrdIn = new Scanner(System.in);
      String password = pswrdIn.nextLine();  
      if (password.equals("123456")){
          Admin admin = new Admin();
          this.adminMenu(writers, admin);
      }				                                                                             //check if login are of admin, open admin menu if true
      else {
        System.out.println("Entered wrong password, try again");
        this.mainMenu(writers);
      }
		}

    else{	
      boolean writerExists = false;
      for(int i=0; i < writers.size(); i++){
        Writer wrt = new Writer();
        wrt = (Writer)writers.get(i);
        
        String usrn = wrt.getUsername();                                                      //check if user exists and open user menu if true

        if (username.equals(usrn)){
          writerExists = true;
          System.out.print("Password: ");
          Scanner pswrdIn = new Scanner(System.in);
          String password = pswrdIn.nextLine();
          String pswd = wrt.getPassword();  
          if (password.equals(pswd)){
            this.writerMenu(writers, wrt);
          }
          else {
            System.out.println("Entered Wrong Pin, try again.");
            this.mainMenu(writers);
          }
          i = writers.size();       
        } 
      }
      if (writerExists == false) {
        System.out.println("No such user exists, try again.");
        this.mainMenu(writers);
      }
    }
  }

	public void adminMenu(Vector writers, Admin adminObj){
		System.out.println("\n");
    System.out.println("--------------------------------------------------");
		System.out.println("Hello Admin, what would you like to do?");
		System.out.println("1. List Users.");
		System.out.println("2. Ban a User.");
    System.out.println("3. List stories.");
		System.out.println("4. Create new story.");
		System.out.println("5. Delete a story.");             //show admin menu options
		System.out.println("6. Log Out");
		System.out.println("7. Exit");
    System.out.print("Choice: ");

		Scanner menuChoice = new Scanner(System.in);
		int choice = menuChoice.nextInt();                                             //create admin object

    switch(choice){
      case 1:
        System.out.println("--------------------------------------------------");
        if (writers.size() != 0){
          adminObj.listWriters(writers);
        }
        else{
          System.out.println("No writers exist");
        }
        this.adminMenu(writers, adminObj);
      case 2:
        System.out.println("--------------------------------------------------");
        System.out.print("Enter writer username to be banned: ");
		    Scanner usrn = new Scanner(System.in);
        String username = usrn.nextLine();						       //ask for user details for deleting
			  adminObj.banWriter(writers, username);
        this.saveData(writers);
			  this.adminMenu(writers, adminObj);
      
      case 3:
        if (adminObj.getStories().size() > 0){
          adminObj.listStories();
        }
        else{
          System.out.println("No stories found.");
        }
        this.adminMenu(writers, adminObj);

      case 4:		
        Vector stories = new Vector();
        stories = adminObj.getStories();
        System.out.print("Enter a new story name: ");
        Scanner storyIn = new Scanner(System.in);
        String storyName = storyIn.nextLine();
        if (stories.contains(storyName)){
          System.out.println("Story already exists, try again.");
        }
        else{
          System.out.print("Enter the beginning sentence: ");
          String firstSentence = storyIn.nextLine();
          adminObj.addNewStory(storyName, firstSentence);
        }
        this.adminMenu(writers, adminObj);

      case 5:
        Vector Stories = new Vector();
        Stories = adminObj.getStories();
        if (Stories.size() > 0){
          System.out.print("Enter the story name to delete: ");
          Scanner storyInp = new Scanner(System.in);
          String storyname = storyInp.nextLine();
          if (Stories.contains(storyname)){
            adminObj.deleteStory(storyname);
            Stories.remove(storyname);
            adminObj.setStories(Stories);
          }
          else{
            System.out.print("Story not found");
          }
        }
        else{
          System.out.println("No stories found.");
        }
        this.adminMenu(writers, adminObj);

      case 6:
        this.saveData(writers);
        System.out.println("--------------------------------------------------");
        System.out.print("Are you sure you want to log out (Y/N): ");
        Scanner logoutChoice = new Scanner(System.in);
        String logoutConfirm = logoutChoice.nextLine();
        if (logoutConfirm.equals("yes") || logoutConfirm.equals("YES") || logoutConfirm.equals("y") || logoutConfirm.equals("Y")){
          System.out.println("Logging out now");
          this.mainMenu(writers);
        }
      else{
        if(logoutConfirm.equals("no") || logoutConfirm.equals("NO") || logoutConfirm.equals("n") || logoutConfirm.equals("N")){
          System.out.println("Taking you back");
        }
        else{
        System.out.println("Invalid Choice, please try again.");
        }
        this.adminMenu(writers, adminObj);
      }

      case 7:
        this.saveData(writers);
        System.out.println("\n");
        System.out.println("--------------------------------------------------");
        System.out.print("Are you sure you want to exit (Y/N): ");
        Scanner exitChoice = new Scanner(System.in);
        String exitConfirm = exitChoice.nextLine();
        if (exitConfirm.equals("yes") || exitConfirm.equals("YES") || exitConfirm.equals("y") || exitConfirm.equals("Y")){
          System.out.println("Exiting now");
          System.exit(0);
        }
        else{
          if(exitConfirm.equals("no") || exitConfirm.equals("NO") || exitConfirm.equals("n") || exitConfirm.equals("N")){
            System.out.println("Taking you back");
          }
          else{
          System.out.println("Invalid Choice, please try again.");
          }
          this.adminMenu(writers, adminObj);
        }
      
      default:
        System.out.println("Invalid Choice, try again");
        this.adminMenu(writers, adminObj);
    }
  }
 
  public void writerMenu(Vector writers, Writer wrtObj){                 			//function to show user menu
		System.out.println();
    System.out.println("--------------------------------------------------");
		System.out.println("1. View public entries");
		System.out.println("2. Create new entry");
		System.out.println("3. List all entries");
		System.out.println("4. Edit old entry");
		System.out.println("5. Delete old entry");
		System.out.println("6. Open StoryTeller game");
		System.out.println("7. Save work and Log Out");
		System.out.println("8. Exit");
    System.out.print("Choice: ");

		Scanner writerChoice = new Scanner(System.in);
		int choice = writerChoice.nextInt();

    switch(choice){
      case 1:
        System.out.println("--------------------------------------------------");
        boolean publicEntriesExist = false;
        for(int i = 0; i < writers.size(); i++){
          Writer wrtr = new Writer();
          wrtr = (Writer)writers.get(i);
          String writerName = wrtr.getUsername();
          Vector entries = wrtr.getEntries();
          for (int j = 0; j < entries.size(); j++){
            Entry entr = new Entry();
            entr = (Entry)entries.get(j);
            boolean isEntryPublic = entr.getPublicStatus();
            if (isEntryPublic == true){
              publicEntriesExist = true;
              String usrEntry = entr.getEntry();
              System.out.println("\n"+ writerName + ":\n" + usrEntry);
              isEntryPublic = false;
            }
          }
        }
        if (publicEntriesExist == false){
          System.out.println("No public entries found.");
        }
        this.writerMenu(writers, wrtObj);

      case 2:
        System.out.println("--------------------------------------------------");
        System.out.println("Enter content for new entry: ");
        Scanner newIn = new Scanner(System.in);
        String newUserEntry = newIn.nextLine();
        
        boolean isPublic = false;
        System.out.print("Do you want this entry to be public (Y/N): ");
        boolean keepGoing = true;
        while (keepGoing){
          Scanner publicIn = new Scanner(System.in);
          String publicStat = publicIn.nextLine();
          
          if (publicStat.equals("Y") || publicStat.equals("y") || publicStat.equals("yes") || publicStat.equals("YES")){
            isPublic = true;
            keepGoing = false;
          }
          else if(publicStat.equals("N") || publicStat.equals("n") || publicStat.equals("no") || publicStat.equals("NO")){
            keepGoing = false;
          }
          else{
            System.out.print("Invalid input. Do you want this entry to be public (Y/N): ");
          }
        }
        wrtObj.newEntry(newUserEntry, isPublic);
        this.saveData(writers);
        this.writerMenu(writers, wrtObj);

      case 3:
        System.out.println("--------------------------------------------------");
        wrtObj.listEntries();
        this.writerMenu(writers, wrtObj);

      case 4:
        System.out.println("--------------------------------------------------");
        wrtObj.editEntry();
        this.saveData(writers);
        this.writerMenu(writers, wrtObj);

      case 5:
        System.out.println("--------------------------------------------------");
        wrtObj.delEntry();
        this.saveData(writers);
        this.writerMenu(writers, wrtObj);
      
      case 6:
        Admin adm = new Admin();
        if (adm.getStories().size() > 0){
          adm.listStories();
          System.out.print("Enter story number to add line to: ");
          Scanner chooseStory = new Scanner(System.in);
          int storyChoice = chooseStory.nextInt();
          if (storyChoice > 0 && storyChoice <= adm.getStories().size()){
            System.out.print("Enter sentence for a story: ");
            Scanner storyLines = new Scanner(System.in);
            String storyLine = storyLines.nextLine();
            String username = wrtObj.getUsername();
            adm.setStory("" + adm.getStories().get(storyChoice-1), username, storyLine);
	    System.out.println("\nStory line added successfully.");
          }
          else{
            System.out.println("Invalid Choice, try again.");
          }
        }
        else{
          System.out.println("No stories found.");
        }
        this.writerMenu(writers, wrtObj);

      case 7:
        this.saveData(writers);
        System.out.println("--------------------------------------------------");
        System.out.print("Are you sure you want to log out (Y/N): ");
        Scanner logoutChoice = new Scanner(System.in);
        String logoutConfirm = logoutChoice.nextLine();
        if (logoutConfirm.equals("yes") || logoutConfirm.equals("YES") || logoutConfirm.equals("y") || logoutConfirm.equals("Y")){
          System.out.println("Logging out now");
          this.mainMenu(writers);
        }
      else{
        if(logoutConfirm.equals("no") || logoutConfirm.equals("NO") || logoutConfirm.equals("n") || logoutConfirm.equals("N")){
          System.out.println("Taking you back");
        }
        else{
        System.out.println("Invalid Choice, please try again.");
        }
        this.writerMenu(writers, wrtObj);
      }

      case 8:
      this.saveData(writers);
      System.out.println("\n");
      System.out.println("--------------------------------------------------");
      System.out.print("Are you sure you want to exit (Y/N): ");
      Scanner exitChoice = new Scanner(System.in);
      String exitConfirm = exitChoice.nextLine();
      if (exitConfirm.equals("yes") || exitConfirm.equals("YES") || exitConfirm.equals("y") || exitConfirm.equals("Y")){
        System.out.println("Exiting now");
        System.exit(0);
      }
      else{
        if(exitConfirm.equals("no") || exitConfirm.equals("NO") || exitConfirm.equals("n") || exitConfirm.equals("N")){
          System.out.println("Taking you back");
        }
        else{
        System.out.println("Invalid Choice, please try again.");
        }
        this.writerMenu(writers, wrtObj);
      }
      break;
      
      default:
        System.out.println("Invalid Choice, try again");
        this.writerMenu(writers, wrtObj);
    }
  }
}
