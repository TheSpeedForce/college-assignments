import java.rmi.*;
import java.util.*;

public class ClientStoreFrontController {
    public static void main(String args[]) {
        try{
            Store frontController = (Store)Naming.lookup("rmi://in-csci-rrpc01.cs.iupui.edu:5000/RemoteStoreFrontController");
            System.out.println("Client calling server");
            
            Scanner input = new Scanner(System.in);  // Create a Scanner object
            System.out.println("Admin or Customer: ");
            String type = input.nextLine();  // Read user input
            
            System.out.println("Enter Username: ");
            String username = input.nextLine();  // Read user input
            
            System.out.println("Enter Password: "); 
            String password = input.nextLine();  // Read user input
            
            input.close();
            
            ArrayList <String> request = new ArrayList<String>();

            request.add(0, type);
            request.add(1, username);
            request.add(2, password);
            System.out.println("-------------------");
            
            UserView view = frontController.dispatchRequest(request);
            view.mainMenu();
		    
        } 
        catch(Exception e) {
            System.out.println("Client err : " + e.getMessage());
            e.printStackTrace();
        }

    }
}