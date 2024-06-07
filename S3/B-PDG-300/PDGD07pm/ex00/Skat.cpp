/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** Skat
*/

#include "Skat.hpp"
#include <iostream>

Skat::Skat(const std::string &name, int stimPaks) : _name(name) {
    this->_name = name;
    this->_stock = stimPaks;
}

Skat::~Skat() {
    return;
}

int &Skat::stimPaks() {
    return this->_stock;
}

const std::string &Skat::name() {
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock) {
    if (number >= stock) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    this->_stock += number;
    stock -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number) {
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    } else {
        this->_stock += number;
    }
}

void Skat::useStimPaks() {
    if (this->_stock > 0) {
        this->_stock--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std:: cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status() {
    std::cout << "Soldier " << this->_name << " reporting " << this->_stock << " stimpaks remaining sir!" << std::endl;
}
