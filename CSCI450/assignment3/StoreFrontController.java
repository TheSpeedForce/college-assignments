import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class StoreFrontController extends UnicastRemoteObject implements Store {
	private Dispatcher dispatcher;

	public StoreFrontController() throws RemoteException{
		dispatcher = new Dispatcher();
	}

	private boolean isAuthenticUser(String username, String password) throws RemoteException{
		boolean authentic = true;  ///change this to false
		User user = UtilFunctions.getUser(username, password);
		System.out.println("StoreFrontController authentication: User is authenticated successfully.");
		System.out.println("--------------------------------------------------------------------------------");
		if (user != null){
			authentic = true;
		}
		return authentic;
	}

	private void trackRequest (ArrayList <String> request) throws RemoteException{
        System.out.println("StoreFrontController tracking: Page requested: " + request.get(0));
		System.out.println("--------------------------------------------------------------------------------");
	}

	public UserView dispatchRequest (ArrayList <String> request) throws RemoteException{
		System.out.println("StoreFrontController tracking request.");
		System.out.println("--------------------------------------------------------------------------------");
		// log each request
		trackRequest(request);
		UserView userView = null;
		String username = request.get(1);
		String password = request.get(2);
		// authenticate the user
		if (isAuthenticUser (username, password)) {
			System.out.println("StoreFrontController dispatching request");
			System.out.println("--------------------------------------------------------------------------------");
			userView = dispatcher.dispatch(request);
		}
		return userView;
	}
}
