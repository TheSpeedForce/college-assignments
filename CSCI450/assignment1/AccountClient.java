import java.rmi.*;

public class AccountClient {
    public static void main(String args[]) {
        try{
            AccountImpl stub = (AccountImpl)Naming.lookup("rmi://in-csci-rrpc01.cs.iupui.edu:5000/RemoteAccount");
            System.out.println("Client calling server");
            
            String name = stub.getName();
            System.out.println("Account Holder: " + name);

            stub.setName("John Raymond");
            name = stub.getName();
            System.out.println("Account Holder: " + name);

            double balance = stub.getBalance().getMoney();
            System.out.println("Current Balance: " + balance);

            Money money = new Money (500);
            stub.setBalance(money);
            balance = stub.getBalance().getMoney();
            System.out.println("Current Balance: " + balance);

            Money withdrawal = new Money (700);
            stub.withdraw(withdrawal);
            balance = stub.getBalance().getMoney();
            System.out.println("Current Balance: " + balance);

            withdrawal = new Money (250);
            stub.withdraw(withdrawal);
            balance = stub.getBalance().getMoney();
            System.out.println("Current Balance: " + balance);

            
            Money deposits = new Money (125);
            stub.deposit(deposits);
            balance = stub.getBalance().getMoney();
            System.out.println("Current Balance: " + balance);

        } catch(Exception e) {
            System.out.println("Client err : " + e.getMessage());
            e.printStackTrace();
        }
    }
}
