# Variables de configuración
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99
GDB_FLAGS = -g
SOURCES = team.c game.c array_helper.c
MAIN_SRC = main.c
TEST_SRC = test.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main
TEST_TARGET = test

# Regla principal para compilar el ejecutable principal con main.c
$(TARGET): $(OBJECTS) $(MAIN_SRC:.c=.o)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(MAIN_SRC:.c=.o)

# Regla para compilar el ejecutable de pruebas con test.c
$(TEST_TARGET): $(OBJECTS) $(TEST_SRC:.c=.o)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJECTS) $(TEST_SRC:.c=.o)

# Regla para compilar cada archivo de código fuente
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto y ejecutables
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(MAIN_SRC:.c=.o) $(TEST_SRC:.c=.o) $(TARGET) $(TEST_TARGET)

# Compilación con depuración para gdb
.PHONY: gdb
gdb: CFLAGS += $(GDB_FLAGS)
gdb: clean $(TARGET)

# Ejecutar el programa principal
.PHONY: run
run: $(TARGET)
	./$(TARGET) input/wc_teams_2022-group.in

