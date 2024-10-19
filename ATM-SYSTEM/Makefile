# Variables
SRC_FILES = src/main.c src/users.c src/hash.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -g # Enable all warnings and debugging info

# Target to build the final executable
atm: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o atm $(OBJ_FILES)

# Rule to compile each .c file into an .o file
src/%.o: src/%.c src/header.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJ_FILES) atm

# Phony targets
.PHONY: clean
