##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME = my_rpg

SRC = 	src/main.c					\
		src/sys.c					\
		src/buttons.c				\
		src/buttons2.c				\
		src/menu.c					\
		src/game.c 					\
		src/my_str_to_word_array.c 	\
		src/my_strcat.c 			\
		src/maps.c 					\
		src/joystick.c				\
		src/cinematique.c 			\
		src/cine2.c 			\
		src/menu_settings.c 		\
		src/menu_settings2.c 		\
		src/menu_settings3.c 		\
		src/tiles.c 				\
		src/nlist.c 				\
		src/editor.c				\
		src/mc.c 					\
		src/init.c					\
		src/editor_sel.c 			\
		src/editor_pal.c 			\
		src/editor_layer.c 			\
		src/editor_status.c 		\
		src/editor_layer2.c 		\
		src/collisions.c 			\
		src/fight.c					\
		src/initfight.c				\
		src/initfight2.c			\
		src/eventfight.c			\
		src/cursor_f.c				\
		src/fight2.c				\
		src/putnbr.c				\
		src/attack.c				\
		src/pause.c 				\
		src/pause2.c 				\
		src/int_to_str.c 			\
		src/map_templates.c 		\
		src/tp.c 					\
		src/npc.c 					\
		src/dialogues.c 			\
		src/quest.c 				\
		src/magie.c					\
		src/fight3.c				\
		src/gameover.c				\
		src/victory.c 				\
		src/boss.c 					\
		src/map_templates2.c 		\
		src/credit.c 				\
		src/inv1.c 					\
		src/inv2.c 					\
		src/inv3.c 					\
		src/inv4.c 					\
		src/inv5.c 					\
		src/keyboard1.c 			\
		src/keyboard2.c 			\
		src/keyboard3.c 			\
		src/keyboard4.c 			\
		src/keyboard5.c 			\
		src/save.c 					\
		src/my_int_to_char.c 		\
		src/get_save.c 				\
		src/get_save2.c 			\
		src/get_save3.c 			\
		src/get_save4.c 			\
		src/my_getbr_tom.c 			\
		src/char_en_char_double.c 	\

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all:
	gcc -o $(NAME) $(SRC) $(CSFML) -g3

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
