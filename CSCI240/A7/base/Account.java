import java.util.Scanner;
import java.io.*;

public class Account implements Serializable{

	protected double balance=0;

	public static void main(String[] args){
		Account a=new Account();
	}
  
  public Account(){
    this.balance = 0;
  }

  public Account(double balance){
    this.balance = balance;
  }

	public double getBalance(){
		return balance;
	}

  public void setBalance(double balance){
    this.balance = balance;
  }

	public void deposit(double money){
		this.balance = this.balance + money;
  }

	public void withdraw(double money){
		this.balance = this.balance - money;
	}
}

