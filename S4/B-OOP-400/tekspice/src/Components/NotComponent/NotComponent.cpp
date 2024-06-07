/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NotComponent
*/

#include "../../../include/nanotekspice.hpp"

nts::NotComponent::NotComponent(std::string name) : AComponent(name) {}

nts::NotComponent::~NotComponent() {}

nts::Tristate nts::NotComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->getLinkCompute(pin);
    else if (pin == 2)
        return this->state;
    else
        return nts::Undefined;
}

void nts::NotComponent::simulate(std::size_t tick) {
    (void) tick;
    nts::Tristate pin1 = this->getLinkCompute(1);
    if (pin1 == nts::Undefined)
        this->changeState(2, nts::Undefined);
    else if (pin1 == nts::True)
        this->changeState(2, nts::False);
    else
        this->changeState(2, nts::True);
}

void nts::NotComponent::changeState(std::size_t pin, nts::Tristate newState) {
    if (pin == 2)
        this->state = newState;
}
