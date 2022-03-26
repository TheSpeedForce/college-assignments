import java.io.*;
import java.util.Vector;
import java.util.Scanner;

public class Menu extends Admin implements Serializable {                                     //class definition begins
	
	public static void main(String[] args){
		Menu menu = new Menu();                                                       //create class object
		Vector users = null;
    try {
		FileInputStream usersFile = new FileInputStream("Users.dat");                 //create file object for input
		ObjectInputStream inputFile = new ObjectInputStream(usersFile);

		users = (Vector)inputFile.readObject();
		
		inputFile.close();                                                            //close inout file                                                           
    }

    catch (IOException ex){
				users = new Vector();
		}

    catch (ClassNotFoundException ex){                      				      //check for errors
			System.out.println("ClassNotFoundException occured");
		}

		menu.loginMenu(users);
	
  }
	
  public void loginMenu(Vector users){							      //function for loggin in

		System.out.println("\nEnter Account Number and Pin to login");
		System.out.println("\nAccount Number: ");
		Scanner accNum = new Scanner(System.in);
		String accountNumber = accNum.nextLine();                                    //ask fot logi credentials

		System.out.println("\nPin Number: ");
		Scanner pin = new Scanner(System.in);
		String PIN = pin.nextLine();
                
    		boolean userExists = false;


		if (accountNumber.equals("00000")){  					      //check if login are of admin, open admin menu if true
			if (PIN.equals("12345")){
				this.adminMenu(users);
			}
			else {
				System.out.println("Entered wrong pin, try again");
				this.loginMenu(users);
			}
		}		

    else {
      for(int i=0; i < users.size(); i++){
        User usr = new User();
        usr = (User)users.get(i);
        
        String acc = usr.getAccNum();
        String pinNum = usr.getPIN();                                                        //check if user exists and open user menu if true

        if (acc.equals(accountNumber)){
	  userExists = true;
          if (pinNum.equals(PIN)){
            this.userMenu(users, usr);
          }
          else {
            System.out.println("\nEntered Wrong Pin, try again.");
            this.loginMenu(users);
          }       
        } 
       }
     }
      if (userExists == false) {
        System.out.println("\nNo such user exists, try again.");
        this.loginMenu(users);
      }
    }

	public void adminMenu(Vector users){
		System.out.println("\n");
		System.out.println("\nHello Admin, what would you like to do?");
		System.out.println("\n1. Add a User");
		System.out.println("\n2. Delete a User");
		System.out.println("\n3. List all Users");
		System.out.println("\n4. Apply Interest to all Savings Accounts");             //show admin menu options
		System.out.println("\n5. Log Out");
		System.out.println("\n6. Exit");
    		System.out.println("\n");

		Scanner menuChoice = new Scanner(System.in);
		int choice = menuChoice.nextInt();                                             //create admin object
		Admin adminObj = new Admin();

		if (choice == 1) {
      System.out.println("\nPlease enter a account number for the User");
		  Scanner accNum = new Scanner(System.in);
      String accountNum = accNum.nextLine();
      System.out.println("\nPlease enter a pin number for the User");                          //ask for details for adding new user
		  Scanner pin = new Scanner(System.in);
      String PIN = pin.nextLine();
      adminObj.addUser(users, accountNum, PIN);						       //add user if doesnt exist already
      this.adminMenu(users);
    }

    else if (choice == 2) {
      System.out.println("\nPlease enter a account number for the User");
		  Scanner accNum = new Scanner(System.in);
      String accountNum = accNum.nextLine();						       //ask for user details for deleting
			adminObj.delUser(users, accountNum);
			this.adminMenu(users);
    }

    else if (choice == 3){								       //liat users by calling class function
      adminObj.listUsers(users);
      this.adminMenu(users);
    }
    else if (choice == 4){
      System.out.println("\nPlease enter a rate of interest: ");
		  Scanner rate = new Scanner(System.in);
      double Rate = rate.nextDouble();
      System.out.println("\nPlease enter time in months: ");                                  //ask rate and time for interest
		  Scanner time = new Scanner(System.in);
      double Time = time.nextDouble();
		  adminObj.applyInterest(users, Rate, Time);                                  //apply interest
      this.adminMenu(users);
    }
    else if (choice == 5){
      try{
        FileOutputStream outUsersFile = new FileOutputStream("Users.dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(outUsersFile);		     //save and close ouput file after storing in it
        outputFile.writeObject(users);
        outUsersFile.close();
        outputFile.close();
      }

      catch(Exception e){
	e.printStackTrace();
        System.out.println("IOException occured");
      }
      this.loginMenu(users);								     //show login menu to log out
    }

		else if (choice == 6) {
      try{
       FileOutputStream outUsersFile = new FileOutputStream("Users.dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(outUsersFile);		     //save and close output file after storing in it
        outputFile.writeObject(users);
        outUsersFile.close();
        outputFile.close();
      }

      catch(Exception e){
        System.out.println("IOException occured");
      }
      System.exit(0);                                                                         //exit
    }

    else {
      System.out.println("Invalid Choice, try again");
      this.adminMenu(users);
    }
  }

	public void userMenu(Vector users, User userObj){                 			//function to show user menu
		System.out.println("\n");
		System.out.println("\n1. Get Checking Balance");
		System.out.println("\n2. Deposit in Checking Account");
		System.out.println("\n3. Withdraw from Checking Account");
		System.out.println("\n4. Get Saving Balance");
		System.out.println("\n5. Deposit in Saving Account");
		System.out.println("\n6. Withdraw in Saving Account");
		System.out.println("\n7. Log Out");
		System.out.println("\n8. Exit");

		Scanner userChoice = new Scanner(System.in);
		int choice = userChoice.nextInt();
    
    if (choice == 1) {
      double checkBal = userObj.getCheckingBalance();
      if (checkBal == 0){
        System.out.println("\nChecking Account has no balance.");                             //check if balance is not 0, show if true
      }
      else {
        System.out.println("\nAvailable Checking Balance: " + checkBal);
      }
      this.userMenu(users, userObj);
    }

    else if (choice == 2) {
      System.out.println("\nEnter money to deposit in checking account: ");
      Scanner checkMoney = new Scanner(System.in);
      double money = checkMoney.nextDouble();
      userObj.depositChecking(money);                                                          //ask for money to deposit and pass as argument to object function
      this.userMenu(users, userObj);
    }

    else if (choice == 3) {
      System.out.println("\nEnter amount you wish to withdraw from checking account: ");
      Scanner withCheckMoney = new Scanner(System.in);
      double money = withCheckMoney.nextDouble();                                               //ask for ammount to withdraw and pass as argument to object function
      userObj.withdrawChecking(money);
      this.userMenu(users, userObj);
    }

    else if (choice == 4){
      double saveBal = userObj.getSavingBalance();
      if (saveBal == 0){
        System.out.println("\nSavings Account has no balance.");                                //check if balance is not 0, show if true
      }
      else {
        System.out.println("\nAvailable Saving Balance: " + saveBal);
      }
      this.userMenu(users, userObj);
    }

    else if (choice == 5) {
      System.out.println("\nEnter money to deposit in savings account: ");
      Scanner saveMoney = new Scanner(System.in);                                              //ask for money to deposit and pass as argument to object function
      double money = saveMoney.nextDouble();
      userObj.depositSaving(money);
      this.userMenu(users, userObj);
    }

    else if (choice == 6) {
      System.out.println("\nEnter amount you wish to withdraw from saving account: ");
      Scanner withSaveMoney = new Scanner(System.in);
      double money = withSaveMoney.nextDouble();                                               //ask for amount to withdraw and pass as argument
      userObj.withdrawSaving(money);
      this.userMenu(users, userObj);
    }

    else if (choice == 7) {
      try{
        FileOutputStream usersFile = new FileOutputStream("Users.dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(usersFile);									
        outputFile.writeObject(users);                                                         //save and close output file
        usersFile.close();
        outputFile.close();
      }

      catch(Exception e){
        System.out.println("IOException occured");
      }
      this.loginMenu(users);
    }

    else if (choice == 8) { 
      try{
        FileOutputStream usersFile = new FileOutputStream("Users.dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(usersFile);									
        outputFile.writeObject(users);                                                          //save and close output file
        usersFile.close();
        outputFile.close();
      }

      catch(Exception e){
        System.out.println("IOException occured");
      }
      System.exit(0);
    }
    else {
      System.out.println("Invalid Choice, try again");
      this.userMenu(users, userObj);
    }
  }
}
