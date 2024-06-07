/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4069Component NOT
*/

#ifndef QUATRE_MILLE_SOIXANTE_NEUF_HPP_
#define QUATRE_MILLE_SOIXANTE_NEUF_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleSoixanteNeufComponent : public nts::AComponent {
        public:
            quatreMilleSoixanteNeufComponent(std::string name);
            ~quatreMilleSoixanteNeufComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_TRENTE_HPP_ */
