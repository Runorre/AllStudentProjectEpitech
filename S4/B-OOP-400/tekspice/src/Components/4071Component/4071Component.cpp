/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4071Component OR
*/

#include "../../../include/nanotekspice.hpp"

nts::quatreMilleSoixanteOnzeComponent::quatreMilleSoixanteOnzeComponent(std::string name) : AComponent(name), state(4) {
    state[0] = nts::Undefined;
    state[1] = nts::Undefined;
    state[2] = nts::Undefined;
    state[3] = nts::Undefined;
}

nts::quatreMilleSoixanteOnzeComponent::~quatreMilleSoixanteOnzeComponent() {}

nts::Tristate nts::quatreMilleSoixanteOnzeComponent::compute(std::size_t pin) {
    if (pin == 1 || pin == 2)
        return this->getLinkCompute(pin);
    else if (pin == 3)
        return this->state[0];
    else if (pin == 5 || pin == 6)
        return this->getLinkCompute(pin);
    else if (pin == 4)
        return this->state[1];
    else if (pin == 13 || pin == 12)
        return this->getLinkCompute(pin);
    else if (pin == 11)
        return this->state[2];
    else if (pin == 9 || pin == 8)
        return this->getLinkCompute(pin);
    else if (pin == 10)
        return this->state[3];
    else
        return nts::Undefined;
}

void nts::quatreMilleSoixanteOnzeComponent::simulate(std::size_t tick) {
    (void) tick;
    nts::Tristate pin1 = this->getLinkCompute(1);
    nts::Tristate pin2 = this->getLinkCompute(2);
    nts::Tristate pin5 = this->getLinkCompute(5);
    nts::Tristate pin6 = this->getLinkCompute(6);
    nts::Tristate pin13 = this->getLinkCompute(13);
    nts::Tristate pin12 = this->getLinkCompute(12);
    nts::Tristate pin9 = this->getLinkCompute(9);
    nts::Tristate pin8 = this->getLinkCompute(8);

    if (pin1 == nts::True || pin2 == nts::True)
        this->changeState(3, nts::True);
    else if (pin1 == nts::Undefined || pin2 == nts::Undefined)
        this->changeState(3, nts::Undefined);
    else
        this->changeState(3, nts::False);

    if (pin5 == nts::True || pin6 == nts::True)
        this->changeState(4, nts::True);
    else if (pin5 == nts::Undefined || pin6 == nts::Undefined)
        this->changeState(4, nts::Undefined);
    else
        this->changeState(4, nts::False);

    if (pin13 == nts::True || pin12 == nts::True)
        this->changeState(11, nts::True);
    else if (pin13 == nts::Undefined || pin12 == nts::Undefined)
        this->changeState(11, nts::Undefined);
    else
        this->changeState(11, nts::False);
    
    if (pin9 == nts::True || pin8 == nts::True)
        this->changeState(10, nts::True);
    else if (pin9 == nts::Undefined || pin8 == nts::Undefined)
        this->changeState(10, nts::Undefined);
    else
        this->changeState(10, nts::False);
}

void nts::quatreMilleSoixanteOnzeComponent::changeState(std::size_t pin, nts::Tristate newState) {
     if (pin == 3)
        this->state[0] = newState;
     if (pin == 4)
        this->state[1] = newState;
     if (pin == 11)
        this->state[2] = newState;
     if (pin == 10)
        this->state[3] = newState;
}
