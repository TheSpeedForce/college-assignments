import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AccountImpl extends UnicastRemoteObject implements Account{

	protected String name = "";
	protected Money balance = null;

	
	public AccountImpl() throws RemoteException{
        super();
		this.name = "";
		this.balance = new Money(); 
	}
	
	// Initializing constructor
	public AccountImpl(String name) throws RemoteException {
        super();
		this.name = name;
		this.balance = new Money();
	}

	public AccountImpl(String name, Money balance) throws RemoteException{
        super();
		this.name = name;
		this.balance = balance;
	}

	public String getName(){
		return this.name;
	}

	public Money getBalance(){
		return this.balance;
	}

	public void setName(String name){
		this.name = name;
	}

	public void setBalance(Money balance){
		this.balance = balance;
	}

	public void deposit(Money money){
        double deposits =  money.getMoney();
		double currentBalance = this.balance.getMoney();
		double newBalance = currentBalance + deposits;
		this.balance.setMoney(newBalance);
        System.out.println("Deposited " + deposits + " successfully.");
	}

	public void withdraw(Money money){
        double withdrawal = money.getMoney();
		double currentBalance = this.balance.getMoney();
		double newBalance = currentBalance - withdrawal;
		if ((newBalance < 0) || (newBalance == currentBalance)){
			System.out.println("Please put appropriate amount for withdrawal");
		}
		else{
			this.balance.setMoney(newBalance);
            System.out.println("Withdrawal of " + withdrawal + " successful.");
		}	
	}
}


	
	