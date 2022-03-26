Menu.class: 	Menu.java Admin.class Writer.class Entry.class
		javac -g Menu.java Admin.java Writer.java Entry.java

Admin.class:	Admin.java Writer.class Entry.class
		javac -g Admin.java Writer.java Entry.java

Writer.class: 	Writer.java Entry.class
		javac -g Writer.java Entry.java

Entry.class:	Entry.java
		javac -g Entry.java

clean:
		rm *.class

run: 		Menu.class
		java Menu

debug:		Menu.class
		jdb Menu
