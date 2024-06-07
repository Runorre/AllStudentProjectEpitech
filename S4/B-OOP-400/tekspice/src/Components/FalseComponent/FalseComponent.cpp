/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** FalseComponent8
*/

#include "../../../include/nanotekspice.hpp"

nts::FalseComponent::FalseComponent(std::string name) : AComponent(name) {}

nts::FalseComponent::~FalseComponent() {}

void nts::FalseComponent::changeState(std::size_t pin, nts::Tristate newState) {
    (void)pin;
    (void)newState;
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->state;
    else
        return nts::Undefined;
}

void nts::FalseComponent::simulate(std::size_t tick) {
    (void)tick;
    this->state = nts::False;
}
