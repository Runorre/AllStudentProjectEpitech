##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade_ncurses.so

SRC = src/NcursesLibGraph.cpp

FLAGS = -Wall -Wextra -std=c++20 -g3 -lncurses

all:
	@echo "COMPILING NCURSES GRAPH LIB!"
	@g++ -shared -o ${NAME} -fPIC ${SRC} ${FLAGS}
	@echo "COMPILATION NCURSES GRAPH LIB IS DONE!"

clean:
	@rm -rf *.o

fclean: clean

re: fclean all