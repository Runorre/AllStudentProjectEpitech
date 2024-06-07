/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name) : Toy(Toy::WOODY, name, "./woody.txt") {}

Woody::Woody(std::string name, std::string ascii) : Toy(Toy::WOODY, name, ascii)  {}


void Woody::speak(std::string text) const {
    std::cout << "WOODY: " << this->getName() << " \"" << text << "\"" << std::endl;
}