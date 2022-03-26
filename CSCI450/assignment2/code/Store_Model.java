import java.util.*;

import org.w3c.dom.UserDataHandler;

import java.io.Serializable;

public class Store_Model implements Serializable{

    private ArrayList<Item> items;
    private ArrayList<User> users;

    public Store_Model (){
        this.items = new ArrayList<Item>();
        this.users = new ArrayList<User>();
    }
    public Store_Model (ArrayList<Item> items, ArrayList<User> users){
        this.items = items;
        this.users = users;
    }

    public ArrayList<Item> getItems () {
        return items;
    }

    public int login (ArrayList<String> credentials) {
        int usenrameCheck = 0;
        int passwordCheck = 2;
        for (User user : users) {
            if (user.getUsername().equals(credentials.get(0))){
                usenrameCheck = 1;
                if (user.getPassword().equals(credentials.get(1))){
                    passwordCheck = 3;
                }
            }
        }
        return usenrameCheck + passwordCheck;
    }

    public void addItem (Customer customer, Item item){

    }
    public void purchaseCart (Customer customer){

    }
    public void updateItem (Admin admin, Item item){

    }
    public void removeItem (Admin admin, Item item){

    }
    public void addCustomer (Customer customer, Customer newCustomer){

    }
    public void removeCustomer (Customer customer, Customer oldCustomer){
        
    }
    public void addAdmin (Admin admin, Admin newAdmin){

    }
    public void removeAdmin (Admin admin, Admin oldAdmin){
        
    }
}
