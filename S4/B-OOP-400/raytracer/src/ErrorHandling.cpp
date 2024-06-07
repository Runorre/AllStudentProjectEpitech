/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** ErrorHandling
*/

#include "../include/main.hpp"
#include "../include/ErrorHandling.hpp"

int ErrorHandling::checkExtension(std::string filename) {
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] == '.' && filename[i + 1] == 'c' && filename[i + 2] == 'f' && filename[i + 3] == 'g') {
            return 0;
        }
    }
    return 84;
}

int ErrorHandling::checkArgs(int ac, char **av) {
    if (ac != 2)
        return 84;
    if (checkExtension(av[1]) == 84)
        return 84;
    std::ifstream file(av[1]);
    if (file.is_open()) {
        std::cerr << "Error: Can't open file" << std::endl;
        return 84;
    }
    return 0;
}