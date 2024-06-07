/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4008Component Adder 4bits
*/

#ifndef QUATRE_MILLE_HUIT_COMPONENT_HPP_
#define QUATRE_MILLE_HUIT_COMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleHuitComponent : public nts::AComponent {
        public:
            quatreMilleHuitComponent(std::string name);
            ~quatreMilleHuitComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;

            nts::Tristate sum(nts::Tristate a, nts::Tristate b, nts::Tristate carry) const;
            // nts::Tristate extractCarry(nts::Tristate sum) const;
            nts::Tristate extractCarry(nts::Tristate a, nts::Tristate b, nts::Tristate carry) const;
            nts::Tristate Xor(nts::Tristate a, nts::Tristate b) const;
            nts::Tristate And(nts::Tristate a, nts::Tristate b) const;
            nts::Tristate Or(nts::Tristate a, nts::Tristate b) const;
    };
}

#endif /* !QUATRE_MILLE_HUIT_COMPONENT_HPP_ */
