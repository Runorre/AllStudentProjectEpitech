##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = mysh

FILE = main.c\
	my_strcat.c\
	my_strcmp.c\
	cd.c\
	my_putstrstr.c\
	my_str_to_word_array2.c\
	signal.c\
	error.c\
	setenv.c\
	order66.c\
	reder.c\
	errorhandeling.c\
	pipe.c

ADDLIB =

MYLIB = -L./lib/my -lmy

W_FLAG = -W -Wall -Wextra -Wuninitialized -g3

LAST_FLAG = -Werror -ansi -pedantic

INC = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(FILE) $(INC) $(ADDLIB) $(MYLIB) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
