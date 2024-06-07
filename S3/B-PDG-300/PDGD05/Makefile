##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for lib
##

SRC =	ex00.c	\
		ex01.c	\
		ex02.c	\
		ex03.c	\
		ex04.c	\
		ex05.c

OBJ = $(SRC: .c = .o)
NAME = libstring.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC) -std=gnu17 -Wall -Wextra
	ar rc $(NAME) *.o
clean:
	rm -f *.o
	rm -f *~
fclean : clean
	rm -f $(NAME)

re: fclean	all
