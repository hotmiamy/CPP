# C Compiler
CC		:=	c++
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -g -std=c++98
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:= zombie

# Headers
HEADER		:=	Zombie.hpp
H_INCLUDE	:=	$(addprefix , $(HEADER))

# Source
SRC			:=	main.cpp Zombie.cpp zombieHorde.cpp

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Inclusions:
INCLUDE		:= $(H_INCLUDE)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJ) 

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Run program using valgrind
vg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log_vg -s ./$(NAME) assets/maps/cube.cub

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR)

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all