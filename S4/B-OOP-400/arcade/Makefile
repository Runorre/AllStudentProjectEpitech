##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade

all: $(NAME)

$(NAME):
	make all -C ./core
	mv ./core/arcade .
	make all -C ./lib/

.PHONY: core
core:
	make all -C ./core
	mv ./core/arcade .

games:
	make all -C ./lib/games

graphicals:
	make all -C ./lib/graphicals

arcade: all

clean:
	make clean -C ./core/
	make clean -C ./lib/
	rm -f arcade

fclean: clean

re : fclean all
