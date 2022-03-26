
all: clean Item.class User.class Customer.class Admin.class Store_Model.class Store_View.class Store.class Store_Controller.class Remote_Store_Controller.class Client_Store_Controller.class rmic

Item.class: Item.java
	javac Item.java

User.class: User.java
	javac User.java

Customer.class: Customer.java User.class Item.class
	javac Customer.java

Admin.class: Admin.java User.class
	javac Admin.java

Store_Model.class: Store_Model.java Admin.class Customer.class User.class Item.class
	javac Store_Model.java

Store_View.class: Store_View.java Admin.class Customer.class User.class Item.class
	javac Store_View.java

Store.class: Store.java Store_View.class Store_Model.class Admin.class Customer.class User.class Item.class
	javac Store.java

Store_Controller.class: Store_Controller.java Store.class Store_Model.class Store_View.class Admin.class Customer.class User.class Item.class
	javac Store_Controller.java

Remote_Store_Controller.class: Remote_Store_Controller.java Store_Controller.class Store.class Store_Model.class Store_View.class Admin.class Customer.class User.class Item.class
	javac Remote_Store_Controller.java

Client_Store_Controller.class: Client_Store_Controller.java Store_Controller.class Store.class Store_Model.class Store_View.class Admin.class Customer.class User.class Item.class
	javac Client_Store_Controller.java

rmic: Store_Controller.class
	rmic Store_Controller

clean:
	rm -rf *.class

run-server: Remote_Store_Controller.class
	java Remote_Store_Controller

run-client: Client_Store_Controller.class
	java Client_Store_Controller