/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4040Component
*/

#ifndef QUATRE_MILLE_QUARANTE_COMPONENT_HPP_
#define QUATRE_MILLE_QUARANTE_COMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleQuaranteComponent : public nts::AComponent {
        public:
            quatreMilleQuaranteComponent(std::string name);
            ~quatreMilleQuaranteComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(size_t pin, nts::Tristate newState);

        protected:
        private:
            int counter = 0;
            std::vector<int> state;


    };
}

#endif /* !QUATRE_MILLE_QUARANTE_COMPONENT_HPP_ */
