/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** logger
*/

#include "../../../include/nanotekspice.hpp"

nts::loggerComponent::loggerComponent(std::string name) : AComponent(name), state(10) {
    state[0] = nts::Undefined;
    state[1] = nts::Undefined;
    state[2] = nts::Undefined;
    state[3] = nts::Undefined;
    state[4] = nts::Undefined;
    state[5] = nts::Undefined;
    state[6] = nts::Undefined;
    state[7] = nts::Undefined;
    state[8] = nts::Undefined;
    state[9] = nts::Undefined;
}

nts::loggerComponent::~loggerComponent() {}

nts::Tristate nts::loggerComponent::compute(std::size_t pin) {
    (void) pin;

    if (pin == 10) {
        return this->state[9];
    }
    if (this->state[9] == nts::True) {
        return nts::Undefined;
    }
    if (pin >= 1 && pin <= 8) {
        return this->state[pin];
    }
    return nts::Undefined;
}

void nts::loggerComponent::simulate(std::size_t tick) {
    (void) tick;
    for (std::size_t i = 1; i <= 10; ++i) {
        if (this->getLinkCompute(i) == nts::Undefined) {
            return;
        }
    }

    nts::Tristate currentClock = this->getLinkCompute(9); // pin 9 clock

    nts::Tristate inhibit = this->getLinkCompute(10); // pin 10 inhibit
    if (currentClock == nts::True && inhibit == nts::False) {
        
        if (inhibit == nts::False) {
            char character = 0;
            character |= (this->getLinkCompute(1) == nts::True ? 1 : 0);
            character |= (this->getLinkCompute(2) == nts::True ? 1 : 0) << 1;
            character |= (this->getLinkCompute(3) == nts::True ? 1 : 0) << 2;
            character |= (this->getLinkCompute(4) == nts::True ? 1 : 0) << 3;
            character |= (this->getLinkCompute(5) == nts::True ? 1 : 0) << 4;
            character |= (this->getLinkCompute(6) == nts::True ? 1 : 0) << 5;
            character |= (this->getLinkCompute(7) == nts::True ? 1 : 0) << 6;
            character |= (this->getLinkCompute(8) == nts::True ? 1 : 0) << 7;
            std::fstream file("./log.bin", std::ios::app | std::ios::out);
            file << character;
            file.close();
        }
    }

    nts::Tristate pin1 = this->getLinkCompute(1); // in_001
    nts::Tristate pin2 = this->getLinkCompute(2); // in_002
    nts::Tristate pin3 = this->getLinkCompute(3); // in_004
    nts::Tristate pin4 = this->getLinkCompute(4); // in_008
    nts::Tristate pin5 = this->getLinkCompute(5); // in_016
    nts::Tristate pin6 = this->getLinkCompute(6); // in_032
    nts::Tristate pin7 = this->getLinkCompute(7); // in_064
    nts::Tristate pin8 = this->getLinkCompute(8); // in_128
    nts::Tristate pin9 = this->getLinkCompute(9); // clock
    nts::Tristate pin10 = this->getLinkCompute(10); // inhibit

    this->changeState(1, pin1);
    this->changeState(2, pin2);
    this->changeState(3, pin3);
    this->changeState(4, pin4);
    this->changeState(5, pin5);
    this->changeState(6, pin6);
    this->changeState(7, pin7);
    this->changeState(8, pin8);
    this->changeState(9, pin9);
    this->changeState(10, pin10);
}

void nts::loggerComponent::changeState(size_t pin, nts::Tristate newState) {
     if (pin == 1)
        this->state[0] = newState;
     if (pin == 2)
        this->state[1] = newState;
     if (pin == 3)
        this->state[2] = newState;
     if (pin == 4)
        this->state[3] = newState;
    if (pin == 5)
        this->state[4] = newState;
     if (pin == 6)
        this->state[5] = newState;
     if (pin == 7)
        this->state[6] = newState;
     if (pin == 8)
        this->state[7] = newState;
    if (pin == 9)
        this->state[8] = newState;
     if (pin == 10)
        this->state[9] = newState;
}