import java.io.*;
import java.util.*;

public class Entry implements Serializable{

	protected String userEntry = "";
  protected boolean isPublic = false;

	public static void main(String[] args){
		Entry e = new Entry();
	}
  
  public Entry(){
    this.userEntry = "";
    this.isPublic = false;
  }

  public Entry(String userEntry, boolean isPublic){
    this.userEntry = userEntry;
    this.isPublic = isPublic;
  }

	public String getEntry(){
		return this.userEntry;
	}

  public void setEntry(String userEntry){
    this.userEntry = userEntry;
  }

  public boolean getPublicStatus(){
    return this.isPublic;
  }
  
  public void setPublicStatus(boolean isPublic){
    this.isPublic = isPublic;
  }
}