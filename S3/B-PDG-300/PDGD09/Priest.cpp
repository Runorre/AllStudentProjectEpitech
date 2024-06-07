/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Peasant(name, power),  Enchanter(name, power) {
    std::cout << this->_name << " enters in the order." << std::endl;
}

Priest::~Priest() {
    std::cout << this->_name << " finds peace." << std::endl;
}

void Priest::rest() {
    this->restGen("prays.", 100, 100);
}
