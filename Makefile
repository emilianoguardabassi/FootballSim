CFLAGS= -Wall -Werror -Wextra -pedantic -std=gnu99 
GDB_FLAGS = -g
SOURCES= main.c team.c game.c array_helper.c 
OBJECTS= $(SOURCES:.c=.o) 
TARGET= test

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

.PHONY: gdb
gdb: CFLAGS += $(GDB_FLAGS)
gdb: clean $(TARGET)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET) input/wc_teams_2022-group.in

