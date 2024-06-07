/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** Federation
*/

#include "Federation.hpp"
#include <string>
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) {
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship() {
    return;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
    this->_coreShip = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
    if (this->_coreShip->checkReactor()->isStable())
        std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain) {
    this->_ledShip = captain;
    std::cout << this->_ledShip->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move() {
    if (this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Federation::Starfleet::Ship::move(Destination d) {
    if (this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d) {
    if (warp > this->_maxWarp || this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Starfleet::Ship::move(int warp) {
    if (warp > this->_maxWarp || this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}



Federation::Starfleet::Captain::Captain(std::string name) {
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain() {
    return;
}

std::string Federation::Starfleet::Captain::getName() {
    return this->_name;
}

int Federation::Starfleet::Captain::getAge() {
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age) {
    this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {
    return;
}



Federation::Ship::Ship(int length, int width, std::string name) {
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = VULCAN;
    this->_location = this->_home;
    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {
    return;
}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
    this->_coreShip = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
    if (this->_coreShip->checkReactor()->isStable())
        std::cout << this->_name << ": The core is stable at the time." << std::endl;
    else
        std::cout << this->_name << ": The core is unstable at the time." << std::endl;
}

bool Federation::Ship::move() {
    if (this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}

bool Federation::Ship::move(Destination d) {
    if (this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Ship::move(int warp, Destination d) {
    if (warp > this->_maxWarp || this->_location == d || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = d;
    return true;
}

bool Federation::Ship::move(int warp) {
    if (warp > this->_maxWarp || this->_location == this->_home || !this->_coreShip->checkReactor()->isStable())
        return false;
    this->_location = this->_home;
    return true;
}
