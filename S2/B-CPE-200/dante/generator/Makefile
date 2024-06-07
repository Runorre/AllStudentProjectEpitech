##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = generator

SRC = main.c\
	initlab.c\
	list.c\
	my_putstrstr.c\
	next.c\
	imperfect.c\
	antinomaze.c\
	my_strcmp.c

ADDLIB =

MYLIB = -L./lib/my -lmy

INCLUDE = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(ADDLIB) $(MYLIB) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
