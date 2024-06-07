/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4008Component Adder 4bits
*/

#include "../../../include/nanotekspice.hpp"

nts::quatreMilleHuitComponent::quatreMilleHuitComponent(std::string name) : AComponent(name), state(5) {
    state[0] = nts::Undefined;
    state[1] = nts::Undefined;
    state[2] = nts::Undefined;
    state[3] = nts::Undefined;
    state[4] = nts::Undefined;
}

nts::quatreMilleHuitComponent::~quatreMilleHuitComponent() {}

nts::Tristate nts::quatreMilleHuitComponent::compute(std::size_t pin) {
    (void) pin;
    if (pin == 15 || pin == 1) {
        return this->getLinkCompute(pin);
    } else if (pin == 2 || pin == 3) {
        return this->getLinkCompute(pin);
    } else if (pin == 4 || pin == 5) {
        return this->getLinkCompute(pin);
    } else if (pin == 6 || pin == 7) {
        return this->getLinkCompute(pin);
    } else if (pin == 13) {
        return this->state[0];
    } else if (pin == 12) {
        return this->state[1];
    } else if (pin == 11) {
        return this->state[2];
    } else if (pin == 10) {
        return this->state[3];
    } else if (pin == 14) {
        return this->state[4];
    } else {
        return nts::Undefined;
    }
}

void nts::quatreMilleHuitComponent::simulate(std::size_t tick) {
    (void) tick;

    // Lecture des entrées
    nts::Tristate pin15 = this->getLinkCompute(15); //in_b4
    nts::Tristate pin1 = this->getLinkCompute(1); //in_a4
    nts::Tristate pin2 = this->getLinkCompute(2); //in_b3
    nts::Tristate pin3 = this->getLinkCompute(3); //in_a3
    nts::Tristate pin4 = this->getLinkCompute(4); //in_b2
    nts::Tristate pin5 = this->getLinkCompute(5); //in_a2
    nts::Tristate pin6 = this->getLinkCompute(6); //in_b1
    nts::Tristate pin7 = this->getLinkCompute(7); //in_a1
    nts::Tristate pin9 = this->getLinkCompute(9); //carry-in

    nts::Tristate sum_0 = sum(pin7, pin6, pin9);
    nts::Tristate carry_1 = extractCarry(pin7, pin6, pin9);
    nts::Tristate sum_1 = sum(pin5, pin4, carry_1);
    nts::Tristate carry_2 = extractCarry(pin4, pin5, carry_1);
    nts::Tristate sum_2 = sum(pin3, pin2, carry_2);
    nts::Tristate carry_3 = extractCarry(pin3, pin2, carry_2);
    nts::Tristate sum_3 = sum(pin1, pin15, carry_3);

    // Calcul de carry_out
    nts::Tristate carry_out = extractCarry(pin1, pin15, carry_3); /*Or(And(pin1, pin6), And(Or(pin1, pin6), pin9)); */ //TODO a changer

    // Mise à jour des sorties
    this->changeState(10, sum_0); // out_0
    this->changeState(11, sum_1); // out_1
    this->changeState(12, sum_2); // out_2
    this->changeState(13, sum_3); // out_3
    this->changeState(14, carry_out); // carry out
}


nts::Tristate nts::quatreMilleHuitComponent::Xor(nts::Tristate a, nts::Tristate b) const {
    if (a == nts::Undefined || b == nts::Undefined) {
        return nts::Undefined;
    } else if (a == nts::True && b == nts::True) {
        return nts::False;
    }  else if (a == nts::True || b == nts::True) {
        return nts::True;
    } else {
        return nts::False;
    }
}

nts::Tristate nts::quatreMilleHuitComponent::And(nts::Tristate a, nts::Tristate b) const {
    if (a == nts::Undefined || b == nts::Undefined) {
        return nts::Undefined;
    } else if (a == nts::True && b == nts::True) {
        return nts::True;
    }  else {
        return nts::False;
    }
}

nts::Tristate nts::quatreMilleHuitComponent::Or(nts::Tristate a, nts::Tristate b) const {
    if (a == nts::Undefined || b == nts::Undefined) {
        return nts::Undefined;
    } else if (a == nts::True || b == nts::True) {
        return nts::True;
    }  else {
        return nts::False;
    }
}

nts::Tristate nts::quatreMilleHuitComponent::sum(nts::Tristate a, nts::Tristate b, nts::Tristate carry) const {
    nts::Tristate sum = Xor(Xor(a, b), carry);
    return sum;
}

nts::Tristate nts::quatreMilleHuitComponent::extractCarry(nts::Tristate a, nts::Tristate b, nts::Tristate carry_in) const {
    nts::Tristate ab = And(a, b);  // Calcul de A.B
    nts::Tristate aOrB = Or(a, b); // Calcul de A + B
    nts::Tristate carry_in_And_aOrB = And(carry_in, aOrB); // Calcul de carry_in . (A + B)
    nts::Tristate carry_out = Or(ab, carry_in_And_aOrB); // Calcul de (A.B) + (carry_in . (A + B))
    return carry_out;
}

void nts::quatreMilleHuitComponent::changeState(size_t pin, nts::Tristate newState) {
    if(pin == 13)
        this->state[0] = newState;
    if(pin == 12)
        this->state[1] = newState;
    if(pin == 11)
        this->state[2] = newState;
    if(pin == 10)
        this->state[3] = newState;
    if(pin == 14)
        this->state[4] = newState;
}