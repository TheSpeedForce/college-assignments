import java.rmi.*;
import java.util.ArrayList;

public class Client_Store_Controller {
    public static void main(String args[]) {
        try{
            Store stub = (Store)Naming.lookup("rmi://in-csci-rrpc01.cs.iupui.edu:5000/Remote_Store_Controller");
            System.out.println("Client calling server");
            ArrayList<String> credentials = stub.getTheView().login();
            int check = stub.getTheModel().login(credentials);
            stub.getTheView().loginCheck(check);
            stub.getTheView().browseItems(stub.getTheModel().getItems());
            
        } 
        catch(Exception e) {
            System.out.println("Client err : " + e.getMessage());
            e.printStackTrace();
        }

    }
}