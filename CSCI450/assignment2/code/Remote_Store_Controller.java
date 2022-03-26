import java.rmi.*;
import java.rmi.registry.*;
import java.util.ArrayList;

public class Remote_Store_Controller {
    public static void main(String args []){
        try {

            // For testing purpose:

            
            Item item1 = new Item ("name1", "type1", "desc1", 45, 6);
            Item item2 = new Item ("name2", "type2", "desc2", 405, 26);
            Item item3 = new Item ();
            Item item4 = new Item ("name4", "type1", "desc5", 745, 60);
            
            ArrayList<Item> items = new ArrayList<Item>();
            items.add(item1);
            items.add(item2);
            items.add(item3);
            items.add(item4);

            
            Customer customer1 = new Customer ("username1", "password1", "John");
            Customer customer2 = new Customer ();
            Admin admin1 = new Admin();
            
            ArrayList<User> users = new ArrayList<User>();
            users.add(customer1);
            users.add(customer2);
            users.add(admin1);

            

            Store_View theView = new Store_View();

    	    Store_Model theModel = new Store_Model(items, users);
        
            Store theController = new Store_Controller(theModel,theView);

            Naming.rebind("rmi://in-csci-rrpc01.cs.iupui.edu:5000/Remote_Store_Controller", theController);
            System.out.println ("Server is ready");
        } 
        catch(Exception e) {
            System.out.println ("Server err: " + e.getMessage());
            e.printStackTrace();
        }
    }
}