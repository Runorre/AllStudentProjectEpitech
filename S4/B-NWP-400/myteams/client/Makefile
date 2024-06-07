##
## EPITECH PROJECT, 2024
## MyTeams
## File description:
## Makefile
##

NAME = myteams_cli

SRC = 	src/client.c	\
		src/command.c\
		src/command2.c\
		src/teams.c\
		src/messages.c\
		src/sends.c\
		src/check_command.c\

$(NAME): all

all:
	gcc -o $(NAME) $(SRC) -I./include -g3 -L../libs/myteams -lmyteams

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
