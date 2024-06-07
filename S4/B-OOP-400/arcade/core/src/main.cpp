/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main
*/

#include "../include/coreArcade.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return 84;

    Machine *mach = new Machine(argv[1]);
    mach->start_machine();
}