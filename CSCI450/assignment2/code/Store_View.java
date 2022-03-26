import java.io.*;
import java.util.*;

public class Store_View implements Serializable{
    private String userType;
    private Admin admin;
    private Customer customer;

    public Store_View () {
        this.userType = "";
        this.admin = new Admin ();
        this.customer = new Customer ();   
    }

    public void showMessage (String message){
        System.out.println (message);

    }
    public ArrayList<String> login () {
        Scanner input = new Scanner(System.in);

        this.showMessage("\nEnter Username and Password to login.\nUsername: ");
		String username = input.nextLine();                                    //ask fot logi credentials

		this.showMessage("\nPassword: ");
		String password = input.nextLine();

        ArrayList<String> credentials = new ArrayList<String>();
        credentials.add(username);
        credentials.add(password);
        
        return credentials;
    }

    public void loginCheck(int check){
        System.out.println("Check" + check);
        if (check == 2)
        {
            System.out.println("Username not found"); 
        }
        else if (check == 3)
        {
            System.out.println("Password incorrect"); 
        }
        else if (check == 4)
        {
            System.out.println("Login Success"); 
        }
        else {
            System.out.println("Error"); 
        } 
    }

    public void browseItems (ArrayList<Item> items) {
        for (Item item : items) {
            System.out.println(item.printItem());
        }

    }

    public void customerMenu (Customer customer){
    }

    public void adminMenu (Admin admin){

    }
}
