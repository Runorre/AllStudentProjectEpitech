/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4040Component
*/

#include "../../../include/nanotekspice.hpp"

nts::quatreMilleQuaranteComponent::quatreMilleQuaranteComponent(std::string name) : AComponent(name), state(12) {
    this->state = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

nts::quatreMilleQuaranteComponent::~quatreMilleQuaranteComponent() {}

size_t getQn(size_t pin) {
    switch (pin) {
        case 1:
            return 12;
        case 2:
            return 6;
            break;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 2;
        case 9:
            return 1;
        case 12:
            return 9;
        case 13:
            return 8;
        case 14:
            return 10;
        case 15:
            return 11;
        default:
            return 1;
    }
}


nts::Tristate nts::quatreMilleQuaranteComponent::compute(std::size_t pin) {
    (void) pin;

    if (pin == 10 || pin == 11) {
        return getLinkCompute(pin);
    }
    if (getLinkCompute(10) == nts::Undefined || getLinkCompute(11) == nts::Undefined) {
        return nts::Undefined;
    }
    switch (this->state[getQn(pin) - 1]) {
        case 0:
            return nts::False;
        case 1:
            return nts::True;
        default:
            return nts::Undefined;
    }
}

void nts::quatreMilleQuaranteComponent::simulate(std::size_t tick) {
    (void)tick;
    Tristate pin10 = getLinkCompute(10); // cl_clock
    Tristate pin11 = getLinkCompute(11); // in_reset

    if (pin10 == nts::Undefined || pin11 == nts::Undefined) {
        this->state = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        changeState(10, nts::Undefined);
        changeState(11, nts::Undefined);
    }

    if (pin11 == nts::True) {
        this->state = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        return;
    }
    if (pin10 == nts::False) {
        for (size_t i = 0; i < this->state.size(); i ++) {
            if (this->state[i] == 0) {
                this->state[i] = 1;
                for (size_t j = 0; j < i; j ++) {
                    this->state[j] = 0;
                }
                break;
            }
        }
    }
}

void nts::quatreMilleQuaranteComponent::changeState(size_t pin, nts::Tristate newState)
{
    (void)pin;
    (void)newState;
}