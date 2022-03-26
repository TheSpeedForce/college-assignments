import java.util.*;
import java.io.*;

public abstract class Pet implements Serializable{

	protected String petName = "";
	protected String petSex = "";
	protected int petAge = 0;
  protected Afraid afraid;
  protected Happiness happiness;
	protected Hunger hunger;
  protected Sleepy sleepy;

	public Pet(String petName, String petSex, int petAge){

		this.petName = petName;
		this.petSex = petSex;
    this.petAge = petAge;
    this.afraid = new Afraid();
    this.happiness = new Happiness();
		this.hunger = new Hunger();
    this.sleepy  = new Sleepy();

	}

	public String getName(){
		return(this.petName);
	}

	public void setName(String name){
		this.petName = name;
	}

	public void setSex(String sex){
		this.petSex = sex;
	}

	public int getAge(){
		return(this.petAge);
	}
	public void setAge(int age){
		this.petAge = age;
	}

	public void play(){

    if(this.sleepy.getValue() >= 90){
      System.out.println("\nI can't play, I'm super sleepy");
    }

		else if(this.hunger.getValue() <= 10){
			System.out.println("\nI can't play, my stomach is full");
    }

    else if(this.hunger.getValue() >= 90){
			System.out.println("\nI can't play, my stomach is empty");
    }
		else{
      this.happiness.upValue(10);
      while (this.happiness.getValue() < 90){
        System.out.println("\nPlay with me more");
				this.happiness.upValue(10);
			}
      System.out.println("\nI am really happy now");
      this.sleepy.upValue((10));
			this.hunger.upValue(10);
		}
	}
  public void sleep(){
		if(this.sleepy.getValue() == 0){
			System.out.println("\nI'm not sleepy at all");
		}

    else if(this.sleepy.getValue() <= 50){
      System.out.println("\nI'm not really sleepy, I dont wanna sleep");
    }

		else{
			System.out.println("\nI'm really sleepy, I am gonna sleep");
      this.sleepy.downValue(50);
      System.out.println("\nI feel refreshed now, and hungry as well");
			this.happiness.upValue(10);
			this.hunger.upValue(10);
		}
	}
  public void walk(){

    if(this.sleepy.getValue() > 70){
      System.out.println("I'm a bit sleepy right now");
    }
    else if(this.hunger.getValue() > 70){
      System.out.println("I'm a bit hungry right now");
    }
    else if(this.afraid.getValue() > 50){
        System.out.println("I'm a bit afraid right now");
    }
    else{
      this.happiness.upValue(10);
      this.hunger.upValue(10);
      this.sleepy.upValue(10);
      System.out.println("I'm happy but sleepy and hungry now!");
    }
  }

	public void feed(){

		if(this.hunger.getValue() == 0){
			System.out.println("\nI dont want to eat, I am full!");
		}
    
    else if(this.hunger.getValue() <= 25){
      System.out.println("\nGive me something small to eat");
    }
    else if(this.hunger.getValue() <= 75){
      System.out.println("\nI am hungry, I want to eat");
    }
		else{
			System.out.println("\nI am really hungry, i want to eat a lot.");
		this.hunger.downValue((10));
		}
  }
}
