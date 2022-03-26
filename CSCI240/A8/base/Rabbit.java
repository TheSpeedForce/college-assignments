import java.util.*;
import java.io.*;

public class Rabbit extends Pet implements Serializable{

  public static void main(String[] args){
		Rabbit rabb = new Rabbit();
    Vector pets = null;
    File petFile = new File("Pets.txt");
		if(petFile.exists())
			rabb.loadPet();
		else
			rabb.newPet(rabb);
		rabb.userMenu();
	}      
  public Rabbit(){
    super("", "", 0);
  }
	public Rabbit(String petName, String petSex, int petAge){

		super(petName, petSex, petAge);
    super.afraid = new Afraid();
    super.happiness = new Happiness();
		super.hunger = new Hunger();
    super.sleepy  = new Sleepy();

	}

public void newPet(Rabbit rabb){
	
		Scanner petDetails = new Scanner(System.in);
		String petName;
    String petSex;
		int petAge = 0;

		System.out.println("\nName of the pet: ");
		petName = petDetails.nextLine();

		System.out.println("\nSex of the pet: ");
		petSex = petDetails.nextLine();

		System.out.println("\nAge(months) of pet: ");
		petAge = petDetails.nextInt();
    while(petAge < 0){
      System.out.println("\nPlease enter a positive value for age: ");
      petAge = petDetails.nextInt();
    }
		rabb = new Rabbit(petName, petSex, petAge);
	}

	public void userMenu(){
		Scanner userChoice = new Scanner(System.in);
		int choice = 0;
		boolean keepGoing = true;
		while(keepGoing == true){

			System.out.println("\n1: Play with it");
			System.out.println("\n2: Make it sleep");
			System.out.println("\n3: Go for a walk");
			System.out.println("\n4: Give it food");
			System.out.println("\n5: Save and Quit");
			choice = userChoice.nextInt();

			try{
        if(choice == 1){
					super.play();
        }

        else if(choice == 2){
					super.sleep();
        }

        else if(choice == 3){
					super.walk(); 
        }

        else if(choice == 4){
					super.feed();
        }

				else if(choice == 5){
          try{
			      FileOutputStream outFile = new FileOutputStream("Pet.dat");
			      ObjectOutputStream fileObj = new ObjectOutputStream(outFile);
            fileObj.writeObject(this);
			      outFile.close();
			      fileObj.close();
			      System.out.println("\nFile saved successful");
	      	}
		      catch(Exception e){
			      System.out.println("\nFile saving unsuccessful");
		      } 
          System.out.println("\nQuitting Program");
					keepGoing = false;
        }
				else
					System.out.println("\nPlease choose from 1 to 5.");
			}
			catch(Exception e){
				System.out.println("\nWrong input, try again.");
		  }
	  }
  }
	public void loadPet(){
    Rabbit petRab;
		try{
			FileInputStream inFile=new FileInputStream("Pet.dat");
			ObjectInputStream fileObj = new ObjectInputStream(inFile);

			petRab = (Rabbit)fileObj.readObject();
      super.setName(petRab.petName);
      super.setSex(petRab.petSex);
      super.setAge(petRab.petAge);
      super.afraid = petRab.afraid;
      super.happiness = petRab.happiness;
      super.hunger = petRab.hunger;
      super.sleepy = petRab.sleepy;
			inFile.close();
			fileObj.close();
			System.out.println("\nFile reading successful");
		}
		catch(Exception e){
			System.out.println("\nFile reading unsuccessful");
		}
	}
}

