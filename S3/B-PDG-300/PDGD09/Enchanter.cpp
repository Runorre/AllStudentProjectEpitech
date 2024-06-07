/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power) {
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter() {
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack() {
    return (this->attackGen(0, "doesn't know how to fight.", 0));
}

int Enchanter::special() {
    return (this->attackGen(99, "casts a fireball.", 50));
}

void Enchanter::rest() {
    return (this->restGen("meditates.", 100, 0));
}
