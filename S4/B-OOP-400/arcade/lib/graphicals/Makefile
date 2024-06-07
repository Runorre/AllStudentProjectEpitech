##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

all:
	@echo "COMPILING GRAPH LIBS!"
	@make -C ./ncurses
	@make -C ./sdl
	@make -C ./sfml
	@mv ./sfml/arcade_sfml.so ..
	@mv ./sdl/arcade_sdl2.so ..
	@mv ./ncurses/arcade_ncurses.so ..
	@echo "COMPILATION GRAPH LIBS IS DONE!"

graphicals: all

clean:
	@rm -rf *.o
	@rm -rf *.so

fclean: clean
	@make clean -C ./ncurses
	@make clean -C ./sdl
	@make clean -C ./sfml

re: fclean all