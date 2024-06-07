##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade_snake.so

SRC = src/snake.cpp

FLAGS = -Wall -Wextra -std=c++20 -g3

all:
	@echo "COMPILING SNAKE GAME LIB!"
	@g++ -shared -o ${NAME} -fPIC ${SRC} ${FLAGS}
	@echo "COMPILATION SNAKE GAME IS DONE!"

clean:
	@rm -rf *.o

fclean: clean

re: fclean all