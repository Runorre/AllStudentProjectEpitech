##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = my_sokoban

SRC = main.c\
	map.c\
	move.c\
	victory.c\
	lose.c\
	error.c\

CSFML = -lncurses

MYLIB = -L./lib/my -lmy

INCLUDE = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(CSFML) $(MYLIB) -g3
		rm -f *.o

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
