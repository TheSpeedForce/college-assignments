import java.io.*;
import java.lang.Math;
import java.util.Vector;
import java.util.Scanner;
public class Admin extends User implements Serializable {                                                         //class definition begins

	protected String accNum = "00000";
	protected String pin = "12345" ;                                                                          //initializing class variables

	public static void main(String[] args){
		Admin adm = new Admin();
	}
  
	public void addUser(Vector users, String accNum, String pin){						//function to add user
    boolean check = true;
    for(int i = 0; i < users.size(); i++){
			User userCheck = new User();
			userCheck = (User)users.get(i);                                                         //check if user exists
			String checkAccNum = userCheck.getAccNum();
			if (checkAccNum.equals(accNum)){
        check = false;
      }
    }
		if (check == false) {
      System.out.println("The account number already exists. Try again");
    }
    else {
		  User newUs = new User(); 
		  newUs.setAccNum(accNum);                                                                      //add user if doesnt exist
      		  newUs.setPIN(pin);
     		  users.add(newUs);
    }
  }

	public void delUser(Vector users, String accNum){
		for(int i = 0; i < users.size(); i++){
			User userCheck = new User();                                                           //get user from all users
			userCheck = (User)users.get(i);

			double checkBal=userCheck.getCheckingBalance();
			double saveBal=userCheck.getSavingBalance();
			String userAccNum = userCheck.getAccNum();
			boolean cantDelete = false;
			if (checkBal != 0.0){
      				cantDelete = true;
			}
			else if (saveBal != 0.0){
				cantDelete = true;
			}

			else if ((accNum).equals(userAccNum)& (cantDelete == false) ){
				users.remove(i);                                                              //delete user if no balance
				System.out.println("Deleted user successfully");
			}
			else {
				System.out.println("Balance in account, unable to delete");
			}
		}
	}
	public void listUsers(Vector users){
		System.out.println("Here is the list of users:");                                             //function to list all users
		for(int i=0; i < users.size(); i++){
			User userShow = new User();
			userShow = (User)users.get(i);
      double checkBal = userShow.checking.getBalance();
      double saveBal = userShow.saving.getBalance();
		  System.out.println("\nUser Account Number: " + userShow.accNum + "\nUser Pin: " + userShow.pin + "\nChecking Balance: " + checkBal + "\nSaving Balance: " + saveBal);
		}	
	}                                                                                                      //print user details

	public void applyInterest(Vector users, double rate, double time){                                     //function to apply interests
		for(int i = 0; i < users.size(); i++){
			User usr = new User();
			usr = (User)users.get(i);                                            
			double savingBal = usr.getSavingBalance();                                             //get saving balance for each user
			if (savingBal != 0){
		  		double interest = savingBal * rate * time;                                     //calculate intrest and add it if balance not 0
      				usr.depositSaving(interest);
			}
		}
	}	
}
