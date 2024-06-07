/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** Borg
*/

#include "Borg.hpp"
#include <string>
#include <iostream>

Borg::Ship::Ship() {
    this->_side = 300;
    this->_maxWarp = 9;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {
    return;
}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
    this->_coreShip = core;
}

void Borg::Ship::checkCore() {
    if (this->_coreShip->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move() {
    if (this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Borg::Ship::move(int warp, Destination d) {
    if (warp > this->_maxWarp || this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(int warp) {
    if (warp > this->_maxWarp || this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Borg::Ship::move(Destination d) {
    if (this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}
