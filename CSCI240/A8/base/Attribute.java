import java.util.*;
import java.io.*;

public abstract class Attribute implements Serializable{
	protected int value = 0;

  public Attribute(){
    this.value = 0;
  }

  public Attribute(int value){
    this.value = value;
  }
  
	public int getValue(){
		return this.value;
	}

  public void setValue(int value){
		this.value = value;
	}

	protected void upValue(int upVal){
    
    if((upVal <= 0)){
			System.out.println("\nPlease enter value greater than 0");
		}
		
    else if((this.value + upVal) > 100){
			System.out.println("\nUnable increase the value by given amount, surpasses maximum value");
		}

		else{
		this.value = this.value + upVal;
	  }
  }

	protected void downValue(int downVal){
     
    if((downVal <= 0)){
			System.out.println("\nPlease enter value greater than 0");
		}

		else if(this.value - downVal <= 0){
			System.out.println("\nUnable decrease the value by given amount, surpasses minimum value");
		}

		else{
      this.value = this.value - downVal;
		}
	}
}
