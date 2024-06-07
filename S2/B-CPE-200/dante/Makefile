##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

SRC = main.c\

all :
		make -C ./solver
		make -C ./generator

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		make fclean -C ./solver
		make fclean -C ./generator

re : fclean all
