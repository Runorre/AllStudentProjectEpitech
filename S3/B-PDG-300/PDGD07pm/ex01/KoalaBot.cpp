/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include <iostream>

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

void KoalaBot::setParts(Arms &part) {
    this->_arms = part;
}

void KoalaBot::setParts(Legs &part) {
    this->_legs = part;
}

void KoalaBot::setParts(Head &part) {
    this->_head = part;
}

void KoalaBot::swapParts(Arms &part) {
    Arms tmp = this->_arms;
    this->_arms = part;
    part = tmp;
}

void KoalaBot::swapParts(Legs &part) {
    Legs tmp = this->_legs;
    this->_legs = part;
    part = tmp;
}

void KoalaBot::swapParts(Head &part) {
    Head tmp = this->_head;
    this->_head = part;
    part = tmp;
}

void KoalaBot::informations() {
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() {
    if (this->_arms.isFunctional() && this->_head.isFunctional() &&
        this->_legs.isFunctional()) {
            return true;
    } else {
        return false;
    }
}
