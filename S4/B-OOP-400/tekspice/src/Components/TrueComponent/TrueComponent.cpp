/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** TrueComponent8
*/

#include "../../../include/nanotekspice.hpp"

nts::TrueComponent::TrueComponent(std::string name) : AComponent(name) {}

nts::TrueComponent::~TrueComponent() {}

void nts::TrueComponent::changeState(std::size_t pin, nts::Tristate newState) {
    (void)pin;
    (void)newState;
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->state;
    else
        return nts::Undefined;
}

void nts::TrueComponent::simulate(std::size_t tick) {
    (void)tick;
    this->state = nts::True;
}
