##
## EPITECH PROJECT, 2024
## zappy
## File description:
## Makefile
##

NAME = zappy

all: $(NAME)

$(NAME):
	@make all -C ./Server
	@make all -C ./GUI
	@make all -C ./AIWithRef
	@make all -C ./AIWithOur
	@mv ./Server/zappy_server .
	@mv ./GUI/zappy_gui .
	@mv ./AIWithRef/zappy_ai .
	@mv ./AIWithOur/zappy_ai_our .

zappy_server:
	@make all -C ./Server
	@mv ./Server/zappy_server .

zappy_gui:
	@make all -C ./GUI
	@mv ./GUI/zappy_gui .

zappy_ai:
	@make all -C ./AIWithRef
	@mv ./AIWithRef/zappy_ai .
	@make all -C ./AIWithOur
	@mv ./AIWithOur/zappy_ai_our .

clean:
	@make clean -C ./Server
	@make clean -C ./GUI
	@make clean -C ./AIWithRef
	@make clean -C ./AIWithOur
	@rm -f ./zappy_server
	@rm -f ./zappy_gui
	@rm -f ./zappy_ai
	@rm -f ./zappy_ai_our

fclean: clean

re: fclean all
