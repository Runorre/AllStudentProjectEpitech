##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lem_in
##

SRC	=	src/lem_in.c \
		src/sprintf.c \
		src/array_utils.c \
		src/error_handling.c \
		src/error_handling_next.c \
		src/graph.c \
		src/my_str_to_word_array_util.c \
		src/my_atoi.c \
		src/my_realloc.c \
		src/my_strtok.c \
		src/my_strdup.c \
		src/linked.c \
		src/my_strchr.c \
		src/hashtable.c \
		src/hashtable_utils.c \
		src/insert_hashtable.c \
		src/my_calloc.c \
		src/algo.c \
		src/free_graph.c \
		src/find_character.c \
		src/printing.c \
		src/error_tmp.c \
		src/parse.c \
		src/dijkstra.c \
		src/init_dijkstra.c \
		src/adam_to_word_array.c \

MYLIB = -L./lib/my -lmy

NAME = lem_in

all:	$(NAME)

W_FLAG = -W -Wall -Wextra -Wuninitialized -g3

LAST_FLAG = -Werror -ansi -pedantic

FLAG_VAL = --tool=memcheck --leak-check=yes --show-reachable=yes

FLAG_VAL2 = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

$(NAME):
		chmod 777 tester.sh
		make re -C ./lib/my/
		gcc $(SRC) $(W_FLAG) $(MYLIB) -I include -o $(NAME) -g -lm

spe:
	gcc $(SRC) $(W_FLAG) $(LAST_FLAG) -I include -o $(NAME) -g -lm

style:	fclean
	coding-style . .
	cat coding-style-reports.log

val:	re
	valgrind $(FLAG_VAL) $(FLAG_VAL2) ./$(NAME) < test/small.txt

push:	fclean
	git add .
	echo git commit -m ""
	echo git push

clean:
		rm -f $(OBJ)
		rm -f coding-style-reports.log
		make clean -C ./lib/my/

fclean: clean
		rm -f $(NAME)
		make fclean -C ./lib/my/
re:		fclean all

.PHONY:	all fclean clean re
