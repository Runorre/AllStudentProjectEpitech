/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** InputComponent8
*/

#include "../../../include/nanotekspice.hpp"

nts::InputComponent::InputComponent(std::string name) : AComponent(name) {}

nts::InputComponent::~InputComponent() {}

void nts::InputComponent::changeState(std::size_t pin, nts::Tristate newState) {
    if (pin == 1)
        this->tmpState = newState;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->state;
    else
        return nts::Undefined;
}

void nts::InputComponent::simulate(std::size_t tick) {
    (void)tick;
    this->state = tmpState;
}
