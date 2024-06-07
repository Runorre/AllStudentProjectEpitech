/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4030Component XOR
*/

#ifndef QUATRE_MILLE_TRENTE_HPP_
#define QUATRE_MILLE_TRENTE_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleTrenteComponent : public nts::AComponent {
        public:
            quatreMilleTrenteComponent(std::string name);
            ~quatreMilleTrenteComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_TRENTE_HPP_ */
