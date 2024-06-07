##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = 42sh

FILE = src/main.c\
	src/my_strcat.c\
	src/my_strcmp.c\
	src/cd.c\
	src/my_putstrstr.c\
	src/my_str_to_word_array2.c\
	src/signal.c\
	src/error.c\
	src/setenv.c\
	src/order66.c\
	src/reder.c\
	src/errorhandeling.c\
	src/alias.c\
	src/list.c\
	src/execalias.c\
	src/unalias.c\
	src/pipe.c \
	src/where.c \
	src/which.c \
	src/echo_builtin.c\
	src/bultins.c\
	src/history.c\
	src/prompt.c\
	src/tty.c\
	src/exclamation.c\
	src/sys.c\

ADDLIB =

MYLIB = -L./lib/my -lmy

W_FLAG = -W -Wall -Wextra -Wuninitialized -g3

LAST_FLAG = -Werror -ansi -pedantic

INC = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(FILE) $(INC) $(ADDLIB) $(MYLIB) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
