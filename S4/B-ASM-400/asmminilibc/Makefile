##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

NAME	=	libasm.so

SRC = strlen.asm \
	strchr.asm	\
	strrchr.asm	\
	memset.asm	\
	strcmp.asm	\
	strncmp.asm	\
	strcasecmp.asm \
	strstr.asm \
	strpbrk.asm	\
	strcspn.asm

OBJ =   $(SRC:.asm=.o)

%.o:    %.asm
	nasm -f elf64 -o $@ $<

all: ${OBJ}
	ld -fPIC -shared $(OBJ) -o $(NAME)
	rm *.o

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re: fclean all