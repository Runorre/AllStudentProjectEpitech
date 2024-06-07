/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name) : Toy(Toy::BUZZ, name, "./buzz.txt") {}

Buzz::Buzz(std::string name, std::string ascii) : Toy(Toy::BUZZ, name, ascii)  {}

