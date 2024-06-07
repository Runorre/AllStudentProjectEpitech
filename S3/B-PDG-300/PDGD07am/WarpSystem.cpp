/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() {
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor() {
    return;
}

bool WarpSystem::QuantumReactor::isStable() {
    return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability) {
    this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor) {
    this->_coreReactor = coreReactor;
}

WarpSystem::Core::~Core() {
    return;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
    return this->_coreReactor;
}
