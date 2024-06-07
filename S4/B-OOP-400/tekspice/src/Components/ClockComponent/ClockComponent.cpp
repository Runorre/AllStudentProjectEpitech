/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NotComponent
*/

#include "../../../include/nanotekspice.hpp"

nts::ClockComponent::ClockComponent(std::string name) : AComponent(name) {}

nts::ClockComponent::~ClockComponent() {}

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->state;
    else
        return nts::Undefined;
}

void nts::ClockComponent::simulate(std::size_t tick) {
    (void) tick;
    if (this->changing) {
        this->state = this->tmpState;
        
        this->changing = false;
    } else {
        if (this->state == nts::True)
            this->state = nts::False;
        else if (this->state == nts::False)
            this->state = nts::True;
    }
}

void nts::ClockComponent::changeState(std::size_t pin, nts::Tristate newState) {
    if (pin == 1) {
        this->tmpState = newState;
        this->changing = true;
    }
}
