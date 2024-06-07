##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade_sfml.so

SRC = 	src/menu.cpp\
		src/SFML.cpp\
		src/game.cpp\

FLAGS = -Wall -Wextra -std=c++20 -g3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:
	@echo "COMPILING SFML GRAPH LIB!"
	@g++ -shared -o ${NAME} -fPIC ${SRC} ${FLAGS}
	@echo "COMPILATION SFML GRAPH LIB IS DONE!"

clean:
	@rm -rf *.o

fclean: clean

re: fclean all