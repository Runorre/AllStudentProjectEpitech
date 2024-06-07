##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

NAME = 	rush3

SRC = 	main.c\
	rush3.c\
	my_putchar.c\
	my_putstr.c\
	my_revstr.c\
	my_put_nbr.c\
	my_strlen.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I./include -g3

clean:
	rm -f *~

fclean:
	rm -f $(NAME)

re: fclean all
