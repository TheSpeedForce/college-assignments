import java.rmi.*;
import java.rmi.registry.*;

public class RemoteAccount {
    public static void main(String args []){
        try {
            Account remote_obj = new AccountImpl();
            Naming.rebind("rmi://in-csci-rrpc01.cs.iupui.edu:5000/RemoteAccount", remote_obj);
            System.out.println ("Server is ready");
        } 
        catch(Exception e) {
            System.out.println ("Server err: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
    
