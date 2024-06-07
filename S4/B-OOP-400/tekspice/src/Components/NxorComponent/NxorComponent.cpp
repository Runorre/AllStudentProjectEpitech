/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NxorComponent
*/

#include "../../../include/nanotekspice.hpp"

nts::NxorComponent::NxorComponent(std::string name) : AComponent(name) {}

nts::NxorComponent::~NxorComponent() {}

nts::Tristate nts::NxorComponent::compute(std::size_t pin) {
    if (pin == 1 || pin == 2)
        return this->getLinkCompute(pin);
    else if (pin == 3)
        return this->state;
    else
        return nts::Undefined;
}

void nts::NxorComponent::simulate(std::size_t tick) {
    (void) tick;
    nts::Tristate pin1 = this->getLinkCompute(1);
    nts::Tristate pin2 = this->getLinkCompute(2);
    if (pin1 == nts::Undefined || pin2 == nts::Undefined)
        this->changeState(3, nts::Undefined);
    else if (pin1 == nts::True && pin2 == nts::True)
        this->changeState(3, nts::True);
    else if (pin1 == nts::True || pin2 == nts::True)
        this->changeState(3, nts::False);
    else
        this->changeState(3, nts::True);
}

void nts::NxorComponent::changeState(std::size_t pin, nts::Tristate newState) {
    if (pin == 3)
        this->state = newState;
}
