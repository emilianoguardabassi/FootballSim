CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 -g 
SOURCE= *.c 
OBJECTS= *.o 
TARGET= test



main:mainobj	
	gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)

mainobj:$(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)


test: testobj 
	gcc main.o team.o game.o array_helper.o -o $(TARGET)

testobj: main.c team.c 
	gcc -c main.c team.c game.c array_helper.c -g

clean:
	rm $(OBJECTS) $(TARGET) 
