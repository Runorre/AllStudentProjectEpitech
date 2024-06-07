##
## EPITECH PROJECT, 2023
## B-CPE-210-MAR-2-1-solostumper01-angelo.anselmet
## File description:
## Makefile
##

NAME = sort_words

FILE = main.c\
     my_putchar.c\

ADDLIB =

MYLIB =

INCLUDE =

all : $(NAME)

$(NAME):
		gcc -o $(NAME) $(FILE) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)

re : fclean all
