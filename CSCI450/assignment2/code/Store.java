import java.rmi.*;

public interface Store extends Remote {

    Store_Model theModel = null;
    Store_View theView = null;

    public Store_View getTheView() throws RemoteException;

    public Store_Model getTheModel() throws RemoteException;
}



	
	