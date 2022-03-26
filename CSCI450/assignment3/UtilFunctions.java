import java.util.*;
import java.io.*;

public class UtilFunctions {
    
    // public static void main (String[] args){
    //     Vector <User> users = new Vector <User> ();
    //     Admin admin1 = new Admin("admin1", "pass1", "Admin1");
    //     Customer customer1 = new Customer("customer1", "cpass1", "customer1");
    //     Customer customer2 = new Customer("customer2", "cpass1", "customer2");
    //     Customer customer3 = new Customer("customer3", "cpass1", "customer3");
    //     users.add(admin1);
    //     users.add(customer1);
    //     users.add(customer2);
    //     users.add(customer3);
    //     System.out.println(users);
    //     writeFile(users, "users");
    //     User a = getUser("admin1", "pass1");
    //     System.out.println(a);
        
        

    // }

    public static User getUser (String username, String password){
        User user = null;
        Vector users = readFile("users");
        for (int i = 0; i < users.size(); i++){
            User temp = (User)users.get(i);
            if (temp.getUsername().equals(username)){
                System.out.println("username found");
                if (temp.getPassword().equals(password)){
                    user = temp;
                }
                break;
            }
        }
        return user;
    }
    
    public static Vector readFile (String filename){
	
        Vector fileData = null;

        try {
            FileInputStream file = new FileInputStream(filename + ".dat"); //create file object for input
            ObjectInputStream object = new ObjectInputStream(file);
            fileData = (Vector)object.readObject();
            object.close();                                                            //close input file      
            
        }
        catch (IOException ex){
	  	    fileData = new Vector();
		}
        catch (ClassNotFoundException ex){                      				      //check for errors
			System.out.println("ClassNotFoundException occured");
		}
        return fileData;

    }
    public static void writeFile(Vector fileData, String filename){
        try{
            FileOutputStream file = new FileOutputStream(filename + ".dat");
            ObjectOutputStream object = new ObjectOutputStream(file);									
            object.writeObject(fileData);                                                          //save and close output file
            file.close();
            object.close();
        }
        catch(Exception e){
            System.out.println("IOException occured");
        }
    }
}
