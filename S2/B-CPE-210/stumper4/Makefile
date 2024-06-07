##
## EPITECH PROJECT, 2023
## MixWord
## File description:
## MixWord
##

NAME		=		mixword

SRC			=		main.c			\
					str_related.c		\
					error_gestion.c		\
					algorithm.c		\
					str_related2.c		\
					check_dir.c		\
					check_dir2.c		\
                    order66.c

OBJ			=		$(SRC:.c=.o)

$(NAME) :
	gcc $(SRC) -o $(NAME) -g3 -I.

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
