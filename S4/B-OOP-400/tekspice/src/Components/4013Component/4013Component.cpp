/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4013Component
*/

#include "../../../include/nanotekspice.hpp"

nts::quatreMilleTreizeComponent::quatreMilleTreizeComponent(std::string name) : AComponent(name), state(4) {
    state[0] = nts::Undefined;
    state[1] = nts::Undefined;
    state[2] = nts::Undefined;
    state[3] = nts::Undefined;
}

nts::quatreMilleTreizeComponent::~quatreMilleTreizeComponent() {}

nts::Tristate nts::quatreMilleTreizeComponent::compute(std::size_t pin) {
    (void) pin;
    if (pin == 5 || pin == 6 || pin == 4) {
        return this->getLinkCompute(pin);
    } else if (pin == 9 || pin == 8 || pin == 10) {
        return this->getLinkCompute(pin);
    } else if (pin == 3) {
        return this->getLinkCompute(pin);
    } else if (pin == 11) {
    return this->getLinkCompute(pin);
    }
    if (pin == 1) {
        return this->state[0];
    } else if (pin == 2) {
        return this->state[1];
    } else if (pin == 13) {
        return this->state[2];
    } else if (pin == 12) {
        return this->state[3];
    } else {
        return nts::Undefined;
    }
}

void nts::quatreMilleTreizeComponent::simulate(std::size_t tick) {
    (void) tick;
    // nts::Tristate pin1 = this->getLinkCompute(1); //out_1_q
    // nts::Tristate pin2 = this->getLinkCompute(2); //out_1_qb
    // nts::Tristate pin13 = this->getLinkCompute(13); //out_2_q
    // nts::Tristate pin12 = this->getLinkCompute(12); //out_2_qb

    nts::Tristate pin3 = this->getLinkCompute(3); //cl_1_clock
    nts::Tristate pin11 = this->getLinkCompute(11); //cl_2_clock

    nts::Tristate pin5 = this->getLinkCompute(5); //in_1_data
    nts::Tristate pin6 = this->getLinkCompute(6); //in_1_set
    nts::Tristate pin4 = this->getLinkCompute(4); //in_1_reset

    nts::Tristate pin9 = this->getLinkCompute(9); //in_2_data
    nts::Tristate pin8 = this->getLinkCompute(8); //in_2_set
    nts::Tristate pin10 = this->getLinkCompute(10); //in_2_reset

    if ((pin5 == nts::Undefined || pin5 == nts::True || pin5 == nts::False) && 
        (pin3 == nts::Undefined || pin3 == nts::True || pin3 == nts::False) &&
        pin6 == nts::True && pin4 == nts::False) {
        changeState(1, nts::True);
        changeState(2, nts::False);
    } else if ((pin5 == nts::Undefined || pin5 == nts::True || pin5 == nts::False) && 
        (pin3 == nts::Undefined || pin3 == nts::True || pin3 == nts::False) &&
        pin6 == nts::False && pin4 == nts::True) {
        changeState(1, nts::False);
        changeState(2, nts::True);
    } else if ((pin5 == nts::Undefined || pin5 == nts::True || pin5 == nts::False) && 
        (pin3 == nts::Undefined || pin3 == nts::True || pin3 == nts::False) &&
        pin6 == nts::True && pin4 == nts::True) {
        changeState(1, nts::True);
        changeState(2, nts::True);
    } else if (pin5 == nts::False && pin3 == nts::True &&
        pin6 == nts::False && pin4 == nts::False) {
        changeState(1, nts::False);
        changeState(2, nts::True);
    } else if (pin5 == nts::True && pin3 == nts::True &&
        pin6 == nts::False && pin4 == nts::False) {
        changeState(1, nts::True);
        changeState(2, nts::False);
    } else {
        changeState(1, nts::Undefined);
        changeState(2, nts::Undefined);
    }

    if ((pin9 == nts::Undefined || pin9 == nts::True || pin9 == nts::False) && 
        (pin11 == nts::Undefined || pin11 == nts::True || pin11 == nts::False) &&
        pin8 == nts::True && pin10 == nts::False) {
        changeState(13, nts::True);
        changeState(12, nts::False);
    } else if ((pin9 == nts::Undefined || pin9 == nts::True || pin9 == nts::False) && 
        (pin11 == nts::Undefined || pin11 == nts::True || pin11 == nts::False) &&
        pin8 == nts::False && pin10 == nts::True) {
        changeState(13, nts::False);
        changeState(12, nts::True);
    } else if ((pin9 == nts::Undefined || pin9 == nts::True || pin9 == nts::False) && 
        (pin11 == nts::Undefined || pin11 == nts::True || pin11 == nts::False) &&
        pin8 == nts::True && pin10 == nts::True) {
        changeState(13, nts::True);
        changeState(12, nts::True);
    } else if (pin9 == nts::False && pin11 == nts::True &&
        pin8 == nts::False && pin10 == nts::False) {
        changeState(13, nts::False);
        changeState(12, nts::True);
    } else if (pin9 == nts::True && pin11 == nts::True &&
        pin8 == nts::False && pin10 == nts::False) {
        changeState(13, nts::True);
        changeState(12, nts::False);
    } else {
        changeState(13, nts::Undefined);
        changeState(12, nts::Undefined);
    }
}

void nts::quatreMilleTreizeComponent::changeState(std::size_t pin, nts::Tristate newState) {
     if (pin == 1)
        this->state[0] = newState;
     if (pin == 2)
        this->state[1] = newState;
     if (pin == 13)
        this->state[2] = newState;
     if (pin == 12)
        this->state[3] = newState;
}
