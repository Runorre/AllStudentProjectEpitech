##
## EPITECH PROJECT, 2023
## B-CPE-210-MAR-2-1-solostumper02-angelo.anselmet
## File description:
## Makefile
##

NAME = anagram

FILE = main.c\

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
