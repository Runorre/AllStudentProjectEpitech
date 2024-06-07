##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade

SRC = src/main.cpp	\
	src/machine/Machine.cpp

FLAGS = -Wall -Wextra -std=c++20 -fno-gnu-unique -g3

all:
	@echo "COMPILING CORE!"
	@g++ ${SRC} -o ${NAME} ${FLAGS}
	@echo "COMPILATION IS CORE DONE!"

core : all

clean:
	@rm -rf *.o

fclean: clean

re: fclean all