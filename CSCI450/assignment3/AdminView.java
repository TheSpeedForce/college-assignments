import java.util.Vector;

public class AdminView implements UserView{
    private Admin admin;
    private AdminCommandFactory adminCF;
    private Vector <Item> items;
    private Vector <User> users;

    // public static void main (String[] args) {
    //     AdminView a = new AdminView("admin1", "pass1");
    //     a.mainMenu();
    // }
    public AdminView () {}

    public AdminView (String username, String password){
        User user = UtilFunctions.getUser(username, password);
        this.admin = new Admin("admin1", "pass1", "admin");
        this.items = UtilFunctions.readFile("items");
        this.users = UtilFunctions.readFile("users");
        
        this.admin.setItems(this.items);
        this.admin.setUsers(this.users);
        this.adminCF = new AdminCommandFactory(this.admin);
    }
    public void mainMenu () {
        
        System.out.println("Admin Menu");
        System.out.println("1. Add Item");
        System.out.println("2. Update Item");
        System.out.println("3. Remove Item");
        System.out.println("1. Add User");
        System.out.println("2. Remove User");
        
        System.out.println("--------------------------------------------------------------------------------");
        
        System.out.println("Adding item");
        System.out.println("Current Items: ");
        System.out.println(this.items);
        Item item = new Item("a","b","c",20,30);
        this.adminCF.setItem(item);
        Command command = this.adminCF.createCommand("add item");
        command.execute();
        this.items = UtilFunctions.readFile("items");
        System.out.println(this.items);
        System.out.println("--------------------------------------------------------------------------------");
        
        System.out.println("Removing User");
        System.out.println("Current users: ");
        System.out.println(this.users);
        User user = this.users.get(0);
        System.out.println("Removing user#1: " + user.getClass());
        adminCF.setUser(user);
        command = adminCF.createCommand("remove user");
        command.execute();
        System.out.println("Current users: ");
        this.users = UtilFunctions.readFile("users");
        System.out.println(this.users);



    }
}
