##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	main.cpp \
		src/Math.cpp \
		src/ErrorHandling.cpp \
		src/RayTracer.cpp \
		src/HitableList.cpp \
		src/Sphere.cpp \
		src/Plane.cpp \
		src/Cylinder.cpp \
		src/Parseur/Parseur/Parseur.cpp \
		src/Parseur/FactoryParseur/FactoryParseur.cpp \
		src/Parseur/FactoryMaterial/FactoryMaterial.cpp \
		src/Cone.cpp \
		src/Light.cpp \

ERRORLIB = src/ErrorHandling.cpp

CPPFLAGS = -g3 -std=c++20 -Wall -Wextra -fPIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lconfig++
SHARED = -fPIC -shared

CC = g++

OBJ = $(SRC:.cpp=.o)

NAME = raytracer

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)
	$(CC) -shared -o libraytracer.so $(OBJ) $(CPPFLAGS) $(LDFLAGS)
	$(CC) -shared -o libmyraytracererror.so $(ERRORLIB) $(CPPFLAGS) $(LDFLAGS)


clean: 
	rm -f *.o
	rm -f *~
	rm -f vgcore.*
	rm -f src/*~
	rm -f src/*.o
	rm -f src/Parseur/BuilderParseur/*.o
	rm -f src/Parseur/FactoryParseur/*.o
	rm -f src/Parseur/FactoryMaterial/*.o
	rm -f src/Parseur/Parseur/*.o
	rm -f *.so

fclean: clean
	rm -f raytracer

re: fclean all
