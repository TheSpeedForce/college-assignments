Rabbit.class: 		Rabbit.java Pet.class Attribute.class Afraid.class Happiness.class Hunger.class Sleepy.class
			javac -g Rabbit.java Pet.java Attribute.java Afraid.java Happiness.java Hunger.java Sleepy.java

Pet.class:		Pet.java Attribute.class Afraid.class Happiness.class Hunger.class Sleepy.class 
			javac -g Pet.java Attribute.java Afraid.java Happiness.java Hunger.java Sleepy.java

Attribute.class:	Attribute.java Afraid.class Happiness.class Hunger.class Sleepy.class
			javac -g Attribute.java Afraid.java Happiness.java Hunger.java Sleepy.java
Afraid.class:		Afraid.java
			javac -g Afraid.java
Happiness.class:	Happiness.java
			javac -g Happiness.java
Hunger.class:		Hunger.java
			javac -g Hunger.java
Sleepy.class:		Sleepy.java
			javac -g Sleepy.java
clean:
			rm *.class

run: 			Rabbit.class
			java Rabbit

debug:			Rabbit.class
			jdb Rbabit
