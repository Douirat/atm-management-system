# Variables
objects = src/main.c src/system.c src/auth.c src/users.c #src/kbd.o src/command.o src/display.o src/insert.o src/search.o src/files.o src/utils.o
OBJ_FILES = $(objects:.c=.o)
# Target to build the final executable
atm : $(OBJ_FILES)
	cc -o atm $(OBJ_FILES)

# Rule to compile each .c file into an .o file
src/%.o: src/%.c src/header.h
	cc -c $< -o $@

# Clean target to remove object files
clean :
	rm -f $(OBJ_FILES)

# Phony targets
.PHONY: clean
