##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

all:
	@echo "COMPILING GAMES LIBS!"
	@make -C ./pacman
	@make -C ./snake
	@mv ./pacman/arcade_pacman.so ..
	@mv ./snake/arcade_snake.so ..
	@echo "COMPILATION GAMES LIBS IS DONE!"

games: all

clean:
	@rm -rf *.o
	@rm -rf *.so

fclean: clean
	@make clean -C ./pacman
	@make clean -C ./snake

re: fclean all