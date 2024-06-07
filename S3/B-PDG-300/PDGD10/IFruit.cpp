/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** IFruit
*/

#include "IFruit.hpp"

bool IFruit::operator==(const IFruit &other) const {
    if (other.getName() == this->getName()) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const IFruit &f) {
    return os << "[name: \"" << f.getName() << "\", vitamins: " << f.getVitamins() << ", peeled: " << std::boolalpha << f.isPeeled() << "]"; 
}
