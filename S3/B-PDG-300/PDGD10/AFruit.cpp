/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit(std::string name, unsigned int vitamin, bool peel) {
    this->_name_ = name;
    this->_vitamin_ = vitamin;
    this->_peel_ = peel;
}

AFruit::~AFruit() {
}

unsigned int AFruit::getVitamins() const {
    if (!this->_peel_)
        return (0);
    return (this->_vitamin_);
}

std::string AFruit::getName() const {
    return (this->_name_);
}

bool AFruit::isPeeled() const {
    return (this->_peel_);
}

void AFruit::peel() {
    this->_peel_ = true;
}
