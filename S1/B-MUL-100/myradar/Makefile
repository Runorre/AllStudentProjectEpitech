##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myradar-angelo.anselmet
## File description:
## Makefile
##

NAME = my_radar

SRC = main.c\
	tower.c\
	plane.c\
	plane2.c\
	my_getnbr.c\
	initgame.c\
	game.c\
	event.c\
	initgames.c\
	hitbox.c

ADDLIB = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

MYLIB = -L./lib/my -lmy

INCLUDE = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(ADDLIB) $(MYLIB) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
