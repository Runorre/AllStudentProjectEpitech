##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for lib
##

SRC =	my_printf.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putstrerr.c \
	my_revstr.c \
	my_strlen.c \
	switch_flag.c \
	my_nbrlen.c \
	converter.c \
	flag.c \
	switch_long_flag.c \
	converter_long.c \
	my_put_float.c \
	my_compute_power_rec.c \
	format.c \
	default.c \
	space.c \
	my_getnbr.c \
	my_str_to_word_array.c \
	order66.c \
	my_strcmp.c \
	my_strcat.c \
	my_strcpy.c \
	my_strncpy.c \
	my_strspn.c \

OBJ = $(SRC: .c = .o)
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC) -I.
	ar rc $(NAME) *.o
clean:
	rm -f *.o
	rm -f *~
fclean : clean
	rm -f $(NAME)

re: fclean 	all
