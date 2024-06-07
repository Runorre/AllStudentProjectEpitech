##
## EPITECH PROJECT, 2024
## MyTeams
## File description:
## Makefile
##

all :
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/libs/myteams
		make -C ./client
		mv ./client/myteams_cli ./myteams_cli
		make -C ./server
		mv ./server/myteams_server ./myteams_server

clean :
		find -name "*~"  -delete
		find -name "#**#" -delete
		find -name "*.gcno" -delete
		find -name "*.gcda" -delete
		find -name "vgcore.*" -delete

fclean : clean
		rm -f myteams_cli
		rm -f myteams_server
		make fclean -C ./client
		make fclean -C ./server

re : fclean all
