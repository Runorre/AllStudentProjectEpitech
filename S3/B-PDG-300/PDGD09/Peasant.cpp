/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power) {
    this->_name = name;
    this->_hp = 100;
    if (power > 100)
        this->_power = 100;
    else if (power < 0)
        this->_power = 0;
    else
        this->_power = power;
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant() {
    std::cout << this->_name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const {
    return this->_name;
}

int Peasant::getPower() const {
    return this->_power;
}

int Peasant::getHp() const {
    return this->_hp;
}

int Peasant::attack() {
    return this->attackGen(5, "tosses a stone.", 10);
}

int Peasant::special() {
    if (this->_hp == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest() {
    this->restGen("takes a nap.", 30, 0);
}

void Peasant::damage(int damage) {
    if (damage >= this->_hp) {
        this->_hp = 0;
        std::cout << this->_name << " is out of combat." << std::endl;
    } else {
        this->_hp -= damage;
        std::cout << this->_name << " takes " << damage << " damage." << std::endl;
    }
    
}

int Peasant::attackGen(int dmg, std::string catchkill, int cost) {

    if (this->_hp == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->_power >= cost) {
        this->_power -= cost;
        std::cout << this->_name << " " << catchkill << std::endl;
        return dmg;
    } else {
        std::cout << this->_name << " is out of power." << std::endl;
        return 0;
    }
}

void Peasant::restGen(std::string catchrest, int regen, int regenHp) {
    if (this->_hp == 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return;
    }
    if ((this->_power + regen) > 100) {
        this->_power = 100;
    } else {
        this->_power += regen;
    }
    if ((this->_hp + regenHp) > 100) {
        this->_hp = 100;
    } else {
        this->_hp += regenHp;
    }
    std::cout << this->_name << " " << catchrest << std::endl;
}
