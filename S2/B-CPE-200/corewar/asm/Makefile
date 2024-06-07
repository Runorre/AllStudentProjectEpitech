##
## EPITECH PROJECT, 2023
## CoreWar
## File description:
## Makefile
##

NAME			=				asm

SRC				=		./src/main.c					\
						./src/parsing.c					\
						./src/str_related.c				\
						./src/output.c					\
						./src/more_str_related.c		\
						./src/functions.c				\
						./src/functions_sec.c			\
						./src/prog_size.c				\


OBJ				=				$(SRC:.c=.o)

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -g3

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
