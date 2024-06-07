##
## EPITECH PROJECT, 2024
## NanotekSpice
## File description:
## Makefile
##

NAME	=	nanotekspice

MAIN = main.cpp

SRC = 		./src/parcing.cpp \
			./src/file.cpp	\
			./src/Components/AComponents/AComponent.cpp \
			./src/Components/InputComponent/InputComponent.cpp \
			./src/Components/OutputComponent/OutputComponent.cpp \
			./src/Components/AndComponent/AndComponent.cpp \
			./src/Components/OrComponent/OrComponent.cpp \
			./src/Components/XorComponent/XorComponent.cpp \
			./src/Components/NotComponent/NotComponent.cpp \
			./src/Components/NxorComponent/NxorComponent.cpp \
			./src/Components/NorComponent/NorComponent.cpp	\
			./src/Components/NandComponent/NandComponent.cpp \
			./src/Components/TrueComponent/TrueComponent.cpp \
			./src/Components/ClockComponent/ClockComponent.cpp \
			./src/Components/FalseComponent/FalseComponent.cpp \
			./src/Components/4001Component/4001Component.cpp \
			./src/Components/4071Component/4071Component.cpp \
			./src/Components/4011Component/4011Component.cpp \
			./src/Components/4081Component/4081Component.cpp \
			./src/Components/4030Component/4030Component.cpp \
			./src/Components/4069Component/4069Component.cpp \
			./src/Components/4008Component/4008Component.cpp \
			./src/Components/LoggerComponent/loggerComponent.cpp \
			./src/Components/4013Component/4013Component.cpp \
			./src/Components/4040Component/4040Component.cpp \
			./src/Factory/Factory.cpp \
			./src/Circuit/Circuit.cpp

TEST_SRC = ./tests/test_nanotekspice.cpp
FLAGS = -Wall -Wextra -std=c++20 -g3
CRITERION_FLAGS = -lcriterion

all:
	@echo "COMPILING!"
	@g++ ${MAIN} ${SRC} -o ${NAME} ${FLAGS}
	@echo "COMPILATION IS DONE!"

tests_run: ${TEST_SRC} ${SRC}
	@echo "COMPILING TESTS!"
	@g++ ${TEST_SRC} ${SRC} -o unit_tests_${NAME} ${FLAGS} ${CRITERION_FLAGS}
	@echo "TEST COMPILATION IS DONE!"
	@./unit_tests_${NAME}

clean:
	@rm -rf *.o
	@rm -f ${NAME} unit_tests_${NAME}

fclean: clean

re: fclean all
