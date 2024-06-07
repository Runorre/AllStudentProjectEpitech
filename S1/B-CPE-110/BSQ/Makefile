##
## EPITECH PROJECT, 2022
## myls
## File description:
## Makefile
##

NAME = bsq

SRC = bsq.c\
	error.c\
	finding.c\
	my_getnbr.c\
	main.c\
	my_putcharstar.c\
	generate.c\
	bsq2.c

SRCL = ./lib/my/my_printf.c\
	./lib/my/my_putchar.c\
	./lib/my/my_put_nbr.c\
	./lib/my/my_putstr.c\
	./lib/my/my_revstr.c\
	./lib/my/my_strlen.c\
	./lib/my/switch_flag.c\
	./lib/my/my_nbrlen.c\
	./lib/my/converter.c\
	./lib/my/flag.c\
	./lib/my/switch_long_flag.c\
	./lib/my/converter_long.c\
	./lib/my/my_put_float.c\
	./lib/my/my_compute_power_rec.c\
	./lib/my/format.c\
	./lib/my/default.c\
	./lib/my/space.c\
	./lib/my/my_getnbr.c\
	./lib/my/my_strcat.c\
	./lib/my/my_str_to_word_array.c\

COMP = libmy.a

all : $(NAME)

$(COMP):
	gcc -c $(SRCL) -I./lib/my
	ar rc ./lib/my/$(COMP) *.o

$(NAME) : $(COMP)
		gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy -g3
		rm -f *.o

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		rm -f ./lib/my/libmy.a

re : fclean all
