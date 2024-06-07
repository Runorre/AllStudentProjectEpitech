/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** OutputComponent
*/

#include "../../../include/nanotekspice.hpp"

nts::OutputComponent::OutputComponent(std::string name) : AComponent(name) {}

nts::OutputComponent::~OutputComponent() {}

void nts::OutputComponent::changeState(std::size_t pin, nts::Tristate newState) {
    if (pin == 1)
        this->tmpState = newState;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin) {
    if (pin == 1) {
        return this->getLinkCompute(1);
    } else
        return nts::Undefined;
}

void nts::OutputComponent::simulate(std::size_t tick) {
    (void)tick;
    this->state = tmpState;
}
