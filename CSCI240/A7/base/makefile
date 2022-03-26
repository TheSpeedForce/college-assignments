Menu.class: 	Menu.java Admin.class User.class Account.class
		javac -g Menu.java Admin.java User.java Account.java

Admin.class:	Admin.java User.class Account.class
		javac -g Admin.java User.java Account.java

User.class: 	User.java Account.class
		javac -g User.java Account.java

Account.class:	Account.java
		javac -g Account.java

clean:
		rm *.class

run: 		Menu.class
		java Menu

debug:		Menu.class
		jdb Menu
