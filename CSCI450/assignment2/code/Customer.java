import java.util.*;

public class Customer extends User{
    protected ArrayList<Item> cart;

    public Customer (){
        super();
        this.cart = new ArrayList<Item>();
    }

    public Customer (String username, String password, String name){
        super(username, password, name);
        this.cart = new ArrayList<Item>();;
    }

    public Customer (String username, String password, String name, ArrayList<Item> cart){
        super(username, password, name);
        this.cart = cart;
    }
}
