##
## EPITECH PROJECT, 2024
## B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
## File description:
## Makefile
##

name	=	MyGKrellm

mod	=	module/IModule.cpp	\
		module/clockwork/Clockwork.cpp	\
		module/cpu/CpuModule.cpp 	\
		module/ram/RamInfo.cpp	\
		module/sysinfo/SystemInfo.cpp	\
		module/battery/BatteryModule.cpp	\
		module/gpu/GpuInfo.cpp \

disp =	display/sfml/SFMLDisplay.cpp	\
		display/ncurses/CurseDisplay.cpp	\

src	=	main.cpp	\
		$(mod)	\
		$(disp)	\

flags	=	-Wall -Wextra -std=c++20

libs	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system

all:
	g++ ${src} -o ${name} ${libs}

clean:
	rm -f ${name}

fclean:	clean

re:	fclean all
