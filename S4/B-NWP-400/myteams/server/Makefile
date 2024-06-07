##
## EPITECH PROJECT, 2024
## MyTeams
## File description:
## Makefile
##

NAME = myteams_server

SRC = 	src/main.c	\
		src/action.c	\
		src/append.c	\
		src/char.c	\
		src/init.c	\
		src/select.c \
		src/mystrtoword.c \
		src/putstr_s.c \
		src/login.c \
		src/new_user.c \
		src/isalldigit.c \
		src/reset.c	\
		src/user.c

$(NAME): all

all:
	gcc -o $(NAME) $(SRC) -I./include -g3 -L../libs/myteams -lmyteams -luuid

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
