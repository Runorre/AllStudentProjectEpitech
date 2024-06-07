##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## To compile project
##

SRC	=	show.c	\
		main.c 	\
		strtowordarray.c\
		flags.c	\
		game.c	\
		my_putstr.c \
		game2.c	\
		flags2.c\
		order66.c

FLAGS	=	-W -Wall -g3

NAME    =       boggle

all : $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -I./include $(FLAGS)

clean:
	find -name "*~" -delete
	find -name "#**#" -delete

fclean: clean
	rm -f $(NAME)

re:	fclean all

