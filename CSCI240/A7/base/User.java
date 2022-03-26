import java.io.*;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class User extends Account implements Serializable {
	protected String accNum="";//account Number
	protected String pin="";//pin number

	protected Account checking;
	protected Account saving;

	public static void main(String[] args){
		User us=new User();
	}

	public User(){
    this.accNum = "";
    this.pin = "";

    this.checking = new Account();
		this.saving = new Account();
	}

  public User(String accNum, String Pin, double checkingBalance, double savingBalance){
    this.accNum = accNum;
    this.pin = pin;

    this.checking = new Account(checkingBalance);
		this.saving = new Account(savingBalance);
  }

	public String getAccNum(){
		return this.accNum;
	}

	public void setAccNum(String accNum){
		this.accNum = accNum;//setting the Account Number
	}

	public String getPIN(){
		return this.pin;
	}

	public void setPIN(String pin){
		this.pin = pin;//setting pin number
	}
  public double getCheckingBalance(){
    return this.checking.getBalance();
  }

  public void depositChecking(double money){
    if (money <= 0){
			System.out.println("Please deposit more than 0");
    }
		else{
      this.checking.deposit(money);
    }
  }

  public void withdrawChecking(double money){
    double balance = this.checking.getBalance();
		if (money > balance) {
			System.out.println("You do not have enough balance");
    }

		else if (money < 0){
			System.out.println("Please enter a value more than 0");
    }

		else{
      this.checking.withdraw(money);
    }
  }

  public double getSavingBalance(){
    return this.saving.getBalance();
  }

  public void depositSaving(double money){
    if (money <= 0){
			System.out.println("Please deposit more than 0");
    }
		else{
      this.saving.deposit(money);
    }
  }

  public void withdrawSaving(double money){
    double balance = this.saving.getBalance();
    if (money > balance){
			System.out.println("You do not have enough balance");
    }

		else if (money <= 0){
			System.out.println("Please enter a value more than 0");
    }

		else{
      this.saving.withdraw(money);
    } 
  }
}
