# GENERAL OPTIONS
# C++ Compiler
CC		:=	c++
# Compiler flags
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:= phonebook

# Source
SRC			+=	main.cpp PhoneBook.cpp Contact.cpp 

#Header
HEADER		:= PhoneBook.hpp Contact.hpp

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles
$(NAME): $(SRC) $(HEADER)
	$(CC) $(FLAGS) -o $@ $(SRC)

$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER) 
	$(CC) $(FLAGS) $@ -c $<

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Run program using valgrind
vg:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR)

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all
