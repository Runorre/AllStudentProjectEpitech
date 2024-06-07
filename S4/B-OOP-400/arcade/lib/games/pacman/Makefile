##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade_pacman.so

SRC = src/pacman.cpp \
		src/game.cpp

FLAGS = -Wall -Wextra -std=c++20 -g3

all:
	@echo "COMPILING PACMAN GAME LIB!"
	@g++ -shared -o ${NAME} -fPIC ${SRC} ${FLAGS}
	@echo "COMPILATION PACMAN GAME IS DONE!"

clean:
	@rm -rf *.o

fclean: clean

re: fclean all