##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

all:
	@echo "COMPILING LIBS!"
	@make -C ./graphicals
	@make -C ./games
	@echo "COMPILATION LIBS IS DONE!"

libs: all

clean:
	@rm -rf *.o
	@rm -rf *.so

fclean: clean
	@make clean -C ./pacman
	@make clean -C ./snake

re: fclean all