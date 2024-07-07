##
## EPITECH PROJECT, 2024
## zappy
## File description:
## Makefile
##

NAME =	 	zappy_gui

CC		=	g++ -g3
RM		=	rm -rf

SRC		= $(shell find src -type f -name "*.cpp")

OBJ		= $(SRC:.cpp=.o)

FLAGS	= 	-std=c++20 -Wall -Wextra -Werror
LDFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	@$(CC) -c $< -o $@ $(FLAGS)

all:	$(NAME)

clean:
	@$(RM) $(OBJ)
	@find . -name "*~" -delete -o -name "#*#" -delete
	@$(RM) vgcore.*
	@$(RM) a.out
	@find . -name "*.gc*" -delete

fclean:	clean
	@$(RM) $(NAME)

re:		fclean all
