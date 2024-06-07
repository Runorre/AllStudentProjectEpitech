##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = my_hunter

SRC = main.c\
	event.c\
	struct.c\
	animationtext.c\
	animationduck.c\
	struct2.c\
	showsprite.c\
	csm.c

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

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
