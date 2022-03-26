import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class Store_Controller extends UnicastRemoteObject implements Store{
    public Store_Model theModel = null;
    public Store_View theView = null;

    public Store_Controller () throws RemoteException {
        super ();
		this.theModel = new Store_Model ();
        this.theView = new Store_View ();
    }
    public Store_Controller (Store_Model theModel, Store_View theView) throws RemoteException {
		super ();
        this.theModel = theModel;
        this.theView = theView;

    }
    public Store_View getTheView() throws RemoteException {
        return theView;
    }

    public Store_Model getTheModel() throws RemoteException {
        return theModel;
    }
}

