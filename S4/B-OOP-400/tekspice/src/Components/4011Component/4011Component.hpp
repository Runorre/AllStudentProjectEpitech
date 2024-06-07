/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4011Component NAND
*/

#ifndef QUATRE_MILLE_ONZE_COMPONENT_HPP_
#define QUATRE_MILLE_ONZE_COMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleOnzeComponent : public nts::AComponent {
        public:
            quatreMilleOnzeComponent(std::string name);
            ~quatreMilleOnzeComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_ONZE_COMPONENT_HPP_ */
