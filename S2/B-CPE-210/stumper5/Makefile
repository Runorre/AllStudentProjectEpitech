##
## EPITECH PROJECT, 2023
## 5_duo
## File description:
## Makefile
##

NAME		=		tictactoe

SRC			=			main.c 			\
						order66.c		\
						recup.c			\
						array_related.c	\
						argu.c			\
						check_win.c		\
						game.c			\

all : $(NAME)

$(NAME)	:
		gcc $(SRC) -o $(NAME) -g3

clean :
		rm -f *.o

fclean : clean
		rm -f $(NAME)

re : fclean all
