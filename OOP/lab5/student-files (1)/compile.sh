#!/bin/bash

echo Testing TSIS...

NAME="OrderItem"
Test="Test"$NAME

javac -g $NAME.java $Test.java
java $Test $NAME Product

NAME="Product"
Test="Test"$NAME
javac -g $NAME.java $Test.java
java $Test $NAME Product

NAME="Coffee"
Test="Test"$NAME
javac -g $NAME.java $Test.java
java $Test $NAME Product

NAME="CoffeeBrewer"
Test="Test"$NAME

javac -g $NAME.java $Test.java
java $Test $NAME Product
