##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = cat

SRC = cat.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean :
	rm -f $(NAME)

re: fclean all
