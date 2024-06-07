/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4001Component NOR
*/

#ifndef QUATRE_MILLE_UN_COMPONENT_HPP_
#define QUATRE_MILLE_UN_COMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleUnComponent : public nts::AComponent {
        public:
            quatreMilleUnComponent(std::string name);
            ~quatreMilleUnComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_UN_COMPONENT_HPP_ */
