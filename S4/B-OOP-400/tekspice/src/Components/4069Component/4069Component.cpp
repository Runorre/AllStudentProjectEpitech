/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4069Component NOT
*/

#include "../../../include/nanotekspice.hpp"

nts::quatreMilleSoixanteNeufComponent::quatreMilleSoixanteNeufComponent(std::string name) : AComponent(name), state(6) {
    state[0] = nts::Undefined;
    state[1] = nts::Undefined;
    state[2] = nts::Undefined;
    state[3] = nts::Undefined;
    state[4] = nts::Undefined;
    state[5] = nts::Undefined;
}

nts::quatreMilleSoixanteNeufComponent::~quatreMilleSoixanteNeufComponent() {}

nts::Tristate nts::quatreMilleSoixanteNeufComponent::compute(std::size_t pin) {
    if (pin == 1)
        return this->getLinkCompute(pin);
    else if (pin == 2)
        return this->state[0];

    if (pin == 3)
        return this->getLinkCompute(pin);
    else if (pin == 4)
        return this->state[1];
    
    if (pin == 5)
        return this->getLinkCompute(pin);
    else if (pin == 6)
        return this->state[2];

    if (pin == 13)
        return this->getLinkCompute(pin);
    else if (pin == 12)
        return this->state[3];

    if (pin == 11)
        return this->getLinkCompute(pin);
    else if (pin == 10)
        return this->state[4];

    if (pin == 9)
        return this->getLinkCompute(pin);
    else if (pin == 8)
        return this->state[5];
    return nts::Undefined;
}

void nts::quatreMilleSoixanteNeufComponent::simulate(std::size_t tick) {
    (void) tick;
    nts::Tristate pin1 = this->getLinkCompute(1);
    nts::Tristate pin3 = this->getLinkCompute(3);
    nts::Tristate pin5 = this->getLinkCompute(5);
    nts::Tristate pin13 = this->getLinkCompute(13);
    nts::Tristate pin11 = this->getLinkCompute(11);
    nts::Tristate pin9 = this->getLinkCompute(9);

    if (pin1 == nts::Undefined)
        this->changeState(2, nts::Undefined);
    else if (pin1 == nts::True)
        this->changeState(2, nts::False);
    else
        this->changeState(2, nts::True);
    
    if (pin3 == nts::Undefined)
        this->changeState(4, nts::Undefined);
    else if (pin3 == nts::True)
        this->changeState(4, nts::False);
    else
        this->changeState(4, nts::True);

    if (pin5 == nts::Undefined)
        this->changeState(6, nts::Undefined);
    else if (pin5 == nts::True)
        this->changeState(6, nts::False);
    else
        this->changeState(6, nts::True);

    if (pin13 == nts::Undefined)
        this->changeState(12, nts::Undefined);
    else if (pin13 == nts::True)
        this->changeState(12, nts::False);
    else
        this->changeState(12, nts::True);
    
    if (pin11 == nts::Undefined)
        this->changeState(10, nts::Undefined);
    else if (pin11 == nts::True)
        this->changeState(10, nts::False);
    else
        this->changeState(10, nts::True);

    if (pin9 == nts::Undefined)
        this->changeState(8, nts::Undefined);
    else if (pin9 == nts::True)
        this->changeState(8, nts::False);
    else
        this->changeState(8, nts::True);
}

void nts::quatreMilleSoixanteNeufComponent::changeState(std::size_t pin, nts::Tristate newState) {
     if (pin == 2)
        this->state[0] = newState;
     if (pin == 4)
        this->state[1] = newState;
     if (pin == 6)
        this->state[2] = newState;
     if (pin == 12)
        this->state[3] = newState;
    if (pin == 10)
        this->state[4] = newState;
    if (pin == 8)
        this->state[5] = newState;
}
