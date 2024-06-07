##
## EPITECH PROJECT, 2022
## B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
## File description:
## Makefile
##

NAME = corewar

SRC = src/main.c\
	src/showhex.c\
	src/createarena.c\
	src/init.c\
	src/arg.c\
	src/getarg.c\
	src/fight.c\
	src/op.c\
	src/function/ld.c\
	src/function/st.c\
	src/function/add.c\
	src/function/sub.c\
	src/function/and.c\
	src/function/or.c\
	src/function/xor.c\
	src/function/zjmp.c\
	src/function/ldi.c\
	src/function/sti.c\
	src/function/fork.c\
	src/function/lld.c\
	src/function/lldi.c\
	src/function/lfork.c\
	src/function/aff.c\
	src/function/live.c\

ADDLIB =

MYLIB = -L./lib/my -lmy

INCLUDE = -I./include

all : $(NAME)

$(NAME) :
		make re -C ./lib/my/
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(ADDLIB) $(MYLIB) -g3

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re : fclean all
