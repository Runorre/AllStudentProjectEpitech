##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	lib/my_putchar.c	\
		lib/my_put_nbr.c	\
		lib/my_strncmp.c	\
		lib/my_strlen.c		\
		lib/my_putstr.c		\
		lib/my_getnbr.c		\
		src/main.c		\
		src/print_error.c	\
		src/checker.c		\
		src/checker2.c		\

NAME 	=	head

INCLUDE =	-I./include

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(INCLUDE) -g3

clean:
	rm -f $(NAME)

fclean: clean
	rm -f ./lib/*~
	rm -f ./lib/*#
	rm -f ./src/*~
	rm -f ./src/*#
	rm -f ./include/*~
	rm -f ./include/*#

re: fclean all
