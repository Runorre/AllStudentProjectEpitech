/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4071Component OR
*/

#ifndef QUATRE_MILLE_SOIXANT_ONZE_HPP_
#define QUATRE_MILLE_SOIXANT_ONZE_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleSoixanteOnzeComponent : public nts::AComponent {
        public:
            quatreMilleSoixanteOnzeComponent(std::string name);
            ~quatreMilleSoixanteOnzeComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_SOIXANT_ONZE_HPP_ */
