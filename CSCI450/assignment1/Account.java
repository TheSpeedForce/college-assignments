import java.rmi.*;

public interface Account extends Remote {

	String name = "";
	Money balance = null;
	
	public String getName();
	public Money getBalance();
	public void setName(String name);
	public void setBalance(Money balance);
	public void deposit(Money money);
	public void withdraw(Money money);

}



	
	