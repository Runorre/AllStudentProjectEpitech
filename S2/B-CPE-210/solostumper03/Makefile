##
## EPITECH PROJECT, 2022
## Stumper
## File description:
## Makefile
##

NAME = fozzbazz

FILE = *.c\

ADDLIB =

MYLIB = -L./lib/my -lmy

INCLUDE = -I./include

all : $(NAME)

$(NAME) :
		gcc -o $(NAME) $(FILE) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)

re : fclean all
