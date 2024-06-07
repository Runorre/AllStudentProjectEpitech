/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::cout << line << '\n';
        }
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i]);
        if (!file) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory\n";
            return 84;
        }
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
    }
    return 0;
}