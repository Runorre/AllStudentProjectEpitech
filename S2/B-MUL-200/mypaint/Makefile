##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC = my_getnbr.c\
	my_nbrlen.c\
	my_put_nbr.c\
	my_putchar.c\
	my_putstr.c\
	my_revstr.c\
	my_strlen.c\
	button.c\
	main.c\
	mainloop.c\
	init.c\
	mouse.c\
	take_nbr.c\
	my_strcat.c\
	init_up_down.c\
	show.c\
	initmenu.c\
	anime.c\
	changemenu.c\
	changefilem.c\
	event.c\
	changehelpm.c\
	event_file.c

NAME = my_paint

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm
all:
	gcc -o $(NAME) $(SRC) -I./includes -g3 $(CSFML)
clean:
	rm -f *.o
	rm -f *~
fclean : clean
	rm -f $(NAME)

re: fclean 	all
