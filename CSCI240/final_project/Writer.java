import java.io.*;
import java.util.*;

public class Writer extends Entry implements Serializable {
	protected String username="";
	protected String password="";
  protected Vector entries = new Vector();

	public static void main(String[] args){
		Writer wr = new Writer();
	}

	public Writer(){
    this.username = "";
    this.password = "";
	}

  public Writer(String username, String password){
    this.username = username;
    this.password = password;
  }

	public String getUsername(){
		return this.username;
	}

	public void setUsername(String username){
		this.username = username;
	}

	public String getPassword(){
		return this.password;
	}

	public void setPassword(String password){
		this.password = password;
	}

  public Vector getEntries(){
    return this.entries;
  }

  public void newEntry(String userEntry, boolean isPublic){
    boolean entryExists = false;
    for(int i = 0; i < this.entries.size(); i++){
      Entry tEntry= new Entry();
      tEntry = (Entry)entries.get(i);
      String usrEntry = tEntry.getEntry();

      if (userEntry.equals(usrEntry)){
        System.out.println("Entry already exists.");
        entryExists = true;
        i = this.entries.size();
      }
    }
    if (entryExists == false){
      Entry newEntr = new Entry(userEntry, isPublic);
      this.entries.add(newEntr);
      System.out.println("Entry added successfully.");
    }
  }

  public void delEntry(){
    if (this.entries.size() == 0){
      System.out.println("No entries found");
    }
    else{
      this.listEntries();
      System.out.print("Enter entry number to delete: ");
      Scanner delEntr = new Scanner(System.in);
      int delChoice = delEntr.nextInt() - 1 ; 
      if (delChoice >= 0 && delChoice < this.entries.size()){
        this.entries.remove(delChoice);
        System.out.println("Entry " + (delChoice + 1) + " deleted successfully"); 
      }
      else{
        System.out.println("Invalid choice, try again.");
      }
    }
  }

  public void editEntry(){
    if (this.entries.size() == 0){
      System.out.println("No entries found");
    }
    else{
      this.listEntries();
      System.out.print("Enter entry number to edit: ");
      Scanner editEntr = new Scanner(System.in);
      int editChoice = editEntr.nextInt() - 1; 
      if (editChoice >= 0 && editChoice < this.entries.size()){
        Entry tEntry= new Entry();
        tEntry = (Entry)entries.get(editChoice);
        System.out.println("Enter edited entry: ");
        Scanner entryIn = new Scanner(System.in);
        String editedEntry = entryIn.nextLine();
        tEntry.setEntry(editedEntry);
        this.entries.set(editChoice, tEntry);
        System.out.println("Entry " + (editChoice + 1) + " edited successfully");
      }
      else{
        System.out.println("Invalid choice, try again.");
      }
    }
  }
  
  public void listEntries(){
    if (this.entries.size() == 0){
      System.out.println("No entries found");
    }
    else {
      for(int i = 0; i < this.entries.size(); i++){
        Entry tEntry= new Entry();
        tEntry = (Entry)entries.get(i);
        String usrEntry = tEntry.getEntry();
        boolean isPublic = tEntry.getPublicStatus();
        int entryNo = i+1;
        System.out.println("\nEntry " + entryNo + ": " + usrEntry +"\nPublic Status: " + isPublic);
      }
    }
  }
}