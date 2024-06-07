##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

all:
	gcc -c *.c
	ar rc libmy.a *.o
	cp libmy.a ../../

clean:
	rm -f *.o
	rm -f *.gca

fclean:
	rm -f libmy.a

re: fclean all
