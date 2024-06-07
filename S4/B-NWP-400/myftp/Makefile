##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME = myftp

SRC = 	src/main.c	\
		src/is_all_digitis.c	\
		src/select_action.c	\
		src/client_action.c	\
		src/login.c			\
		src/my_str_to_word_array.c	\
		src/path.c	\
		src/strcat_realloc.c	\
		src/commands.c	\
		src/char.c	\
		src/delete.c

$(NAME): all

all:
	gcc -o $(NAME) $(SRC) -I./include -g3

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
