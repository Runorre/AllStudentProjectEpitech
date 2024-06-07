/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** Parts
*/

#include "Parts.hpp"
#include <iostream>

Arms::Arms(const std::string &serial, bool functional) {
    this->_serial = serial;
    this->_functional = functional;
}

bool Arms::isFunctional() {
    return this->_functional;
}

std::string Arms::serial() {
    return this->_serial;
}

void Arms::informations() {
    if (this ->_functional) {
        std::cout << "[Parts] Arms " << this->_serial << " status : OK" << std::endl;
    } else {
        std::cout << "[Parts] Arms " << this->_serial << " status : KO" << std::endl;
    }
}

Legs::Legs(const std::string &serial, bool functional) {
    this->_serial = serial;
    this->_functional = functional;
}

bool Legs::isFunctional() {
    return this->_functional;
}

std::string Legs::serial() {
    return this->_serial;
}

void Legs::informations() {
    if (this ->_functional) {
        std::cout << "[Parts] Legs " << this->_serial << " status : OK" << std::endl;
    } else {
        std::cout << "[Parts] Legs " << this->_serial << " status : KO" << std::endl;
    }
}

Head::Head(const std::string &serial, bool functional) {
    this->_serial = serial;
    this->_functional = functional;
}

bool Head::isFunctional() {
    return this->_functional;
}

std::string Head::serial() {
    return this->_serial;
}

void Head::informations() {
    if (this ->_functional) {
        std::cout << "[Parts] Head " << this->_serial << " status : OK" << std::endl;
    } else {
        std::cout << "[Parts] Head " << this->_serial << " status : KO" << std::endl;
    }
}
