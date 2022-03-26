import java.util.*;

public class CustomerView implements UserView{
    private Customer customer;
    private CustomerCommandFactory customerCF;
    private Vector <Item> items;
    
    public CustomerView () {}

    public CustomerView (String username, String password){
        User user = UtilFunctions.getUser(username, password);
        this.customer = new Customer(username, password, "customer");
        this.items = UtilFunctions.readFile("items");
        this.customerCF = new CustomerCommandFactory(customer);
    }
    public void mainMenu () {
        
        System.out.println("Customer Menu:");
        System.out.println("1. Browse Items");
        System.out.println("2. Purchase Cart.");
        System.out.println("3. Log out");
        System.out.println("--------------------------------------------------------------------------------");
        
        Command command;
        
        command = customerCF.createCommand("browse items");
        command.execute();
        
        System.out.println("Current Cart and orders");
        
        System.out.println("Cart");
        System.out.println(this.customer.getCart());
        System.out.println("Orders");
        System.out.println(this.customer.getOrders());
        System.out.println("--------------------------------------------------------------------------------");
        
        System.out.println("Adding item to Cart");
        
        int itemNum = 1;
        Item item = items.get(itemNum);
        customerCF.setItem(item);
        command = customerCF.createCommand("add to cart");
        command.execute();
        
        System.out.println("Cart");
        System.out.println(this.customer.getCart());
        System.out.println("Orders");
        System.out.println(this.customer.getOrders());
        System.out.println("--------------------------------------------------------------------------------");
        
        System.out.println("Purchasing Cart");
        command = customerCF.createCommand("purchase cart");
        command.execute();
        System.out.println("Cart");
        System.out.println(this.customer.getCart());
        System.out.println("Orders");
        System.out.println(this.customer.getOrders());
        System.out.println("--------------------------------------------------------------------------------");
       
        


    }
}
