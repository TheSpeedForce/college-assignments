import java.io.*;
import java.util.*;
public class Admin extends Writer implements Serializable {                                                         //class definition begins

	protected String username = "admin";
	protected String password = "123456" ;                                                                         //initializing class variables
	public static void main(String[] args){
		Admin adm = new Admin();
	}

  public void listWriters(Vector writers){
		System.out.println("Here is the list of writers:");                                             //function to list all users
		for(int i=0; i < writers.size(); i++){
			Writer wrtr = new Writer();
			wrtr = (Writer)writers.get(i);
      String username = wrtr.getUsername();
      String password = wrtr.getPassword();
      Vector entries = new Vector();
      entries = wrtr.getEntries();
      int entriesSize = entries.size();
		  System.out.println("\n|Username: " + username + " |Password: " + password + " |Number of entries: " + entriesSize + " |");
		}
  }	
	
  
	public void banWriter(Vector writers, String username){						//function to add user
    boolean writerExists = false;
    for(int i = 0; i < writers.size(); i++){
      Writer wrtr = new Writer();
      wrtr = (Writer)writers.get(i);
      String usrn = wrtr.getUsername();
      if ((username).equals(usrn)){
        writers.remove(i);
        System.out.println("Writer banned successfully.");
        writerExists = true;
        i = writers.size();
      }
    }
		if (writerExists == false) {
      System.out.println("The writer does not exist.");
    }
  }

  public Vector getStory(String storyName){
    Vector story = new Vector();
    Vector stories = new Vector();
    stories = this.getStories();
    if (stories.contains(storyName)){  
      try{
        FileInputStream storyFile = new FileInputStream(storyName + ".dat");
        ObjectInputStream inputFile = new ObjectInputStream(storyFile);	
        story = (Vector)inputFile.readObject();
        storyFile.close();
        inputFile.close();
      }
      catch(Exception ex){
        System.out.println("Exception Occured.");
      }
    }
    return story;
  }

  public void setStory(String storyName, String username, String storyLine){
    Vector story = new Vector();
    Vector stories = new Vector();
    stories = this.getStories();
    if (stories.contains(storyName)){
      story = this.getStory(storyName);
      Vector storyEntry = new Vector();
      storyEntry.add(username);
      storyEntry.add(storyLine);
      story.add(storyEntry);
      try{
        FileOutputStream storyFile = new FileOutputStream(storyName + ".dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(storyFile);	
        outputFile.writeObject(story);
        storyFile.close();
        outputFile.close();
      }
      catch(Exception ex){
        System.out.println("Exception occurred.");
      }
    }
    else{
      System.out.println("Story not found.");
    }
  }

  public void addNewStory(String storyName, String firstSentence){
      try{
        FileOutputStream storyFile = new FileOutputStream(storyName + ".dat");
        ObjectOutputStream outputFile = new ObjectOutputStream(storyFile);	
        Vector storyEntry = new Vector();
        storyEntry.add("admin");
        storyEntry.add(firstSentence);
        Vector story = new Vector();
        story.add(storyEntry);								
        outputFile.writeObject(story);                                                        //save and close output file
        storyFile.close();
        outputFile.close();

        Vector stories = new Vector();
        stories = this.getStories();
        stories.add(storyName);
        this.setStories(stories);
	System.out.println("\nStory added successfully.");	
      }
      catch(Exception e){
        System.out.println("IOException occured");
      }
    }

  public void deleteStory(String storyName){
    try{
      File storyFile = new File("" + storyName + ".dat");
      if (storyFile.delete()){
        Vector stories = new Vector();
        stories = this.getStories();
        stories.remove(storyName);
        this.setStories(stories);
        System.out.println("Story deleted successfully.");
      }
      else{
        System.out.println("Story not found.");
      }
    }
    catch(Exception e){
      System.out.println("IOException occured");
    }
  }

  public void listStories(){
    Vector stories = new Vector();
    stories = this.getStories();
    for (int i = 0; i < stories.size(); i++){
      String storyName = (String)stories.get(i);
      Vector story = new Vector();
      story = getStory(storyName);
      System.out.println("\n" + (i+1) + ". " + storyName);
      for (int j = 0; j < story.size(); j++){
        Vector storyLine = new Vector();
        storyLine = (Vector)story.get(j);
        System.out.println("\n" + storyLine.get(0) + ": " + storyLine.get(1));
      }
    }
  }

  public Vector getStories(){
    Vector stories = new Vector();
    try{
      FileInputStream storiesFile = new FileInputStream("stories.dat");
      ObjectInputStream inFile = new ObjectInputStream(storiesFile);	
      stories = (Vector)inFile.readObject();//save and close output file
      storiesFile.close();
      inFile.close();
    }
    catch(Exception ex){
      System.out.println("Exception occured.");
    }
    return stories;
  }

  public void setStories(Vector stories){
    try{
      FileOutputStream storiesFile = new FileOutputStream("stories.dat");
      ObjectOutputStream outputFile = new ObjectOutputStream(storiesFile);
      outputFile.writeObject(stories);
      storiesFile.close();
      outputFile.close();
    }
    catch(Exception ex){
      System.out.println("Exception Occured.");
    }
  }
}
