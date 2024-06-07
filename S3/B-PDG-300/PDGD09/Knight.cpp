/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string &name, int power) : Peasant(name, power) {
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

int Knight::attack() {
    return this->attackGen(20, "strikes with his sword.", 10);
}

int Knight::special() {
    return this->attackGen(50, "impales his enemy.", 30);
}

void Knight::rest() {
    this->restGen("eats.", 50, 0);
}

Knight::~Knight() {
    std::cout << this->_name << " takes off his armor." << std::endl;
}
