##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME = arcade_sdl2.so

SRC = 	src/SDL.cpp \

FLAGS = -Wall -Wextra -std=c++20 -g3 -lSDL2 -lSDL2_ttf -lSDL2_image

all:
	@echo "COMPILING SDL GRAPH LIB!"
	@g++ -shared -o ${NAME} -fPIC ${SRC} ${FLAGS}
	@echo "COMPILATION SDL GRAPH LIB IS DONE!"

clean:
	@rm -rf *.o

fclean: clean

re: fclean all
