# GENERAL OPTIONS
# C++ Compiler
CC		:=	c++
# Compiler flags
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:= megaphone

# Source
SRC			:=	megaphone.cpp

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $@ $<

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Run program using valgrind
vg:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all
